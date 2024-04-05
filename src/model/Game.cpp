#include <algorithm>
#include <stdexcept>

#include "Game.h"

void Game::addObserver(Observer &observer) {
    observers.emplace_back(&observer);
}

void Game::notifyObservers() {
    std::for_each(observers.begin(), observers.end(), [](std::shared_ptr<Observer>& observer) {
        observer->update();
    });
}

void Game::removeObserver(const int pos) {
    observers.erase(observers.begin() + pos);
}

void Game::start() {
    if (hasStarted) {
        throw std::runtime_error("Game has already started.");
    }
    checkTargets();
    hasStarted = true;
    board = Board(boardWidth, boardHeight, difficulty);
    board.addTetromino(bag.getNext());
    notifyObservers();
}

void Game::checkTargets() const {
    if (boardWidth < Board::MIN_BOARD_WIDTH || boardHeight < Board::MIN_BOARD_HEIGHT ||
        boardWidth > Board::MAX_BOARD_WIDTH || boardHeight > Board::MAX_BOARD_HEIGHT) {
        throw std::invalid_argument("Invalid Board Size, please try again.");
    }
    if (difficulty < Board::MIN_DIFFICULTY || difficulty > Board::MAX_DIFFICULTY) {
        throw std::invalid_argument("Invalid difficulty, please try again.");
    }
    if (currentLevel < 0) {
        throw std::invalid_argument("Invalid level, please try again.");
    }
    if (targetScore < 0 || targetTime < 0 || targetLine < 0) {
        throw std::invalid_argument("Invalid game parameter, please try again.");
    }
}

void Game::restart() {
    resetScore();
    hasStarted = false;
    start();
    notifyObservers();
}

void Game::resetScore() {
    currentScore = 0;
    currentLevel = START_LEVEL;
    currentLine = 0;
    currentTime = 0;
}

void Game::moveActiveTetromino(Direction2D direction) {
    if (hasStarted && !isGameOver() && !isWinner()) {
        try {
            board.moveActiveTetromino(direction);
        }
        catch (const std::exception &) {
            if (direction == Direction::DOWN) {
                updateScore(board.removeCompleteLines(), 0);
                board.addTetromino(bag.getNext());
            }
        }
    }
    notifyObservers();
}

void Game::rotateActiveTetromino(Rotation rotation) {
    if (hasStarted && !isGameOver() && !isWinner() && board.activeTetrominoIsRotatable()) {
        try {
            board.rotateActiveTetromino(rotation);
        }
        catch (const std::out_of_range &) {
            if (board.activeTetroIsBellow(boardHeight - 2)) {
                updateScore(board.removeCompleteLines(), 0);
                board.addTetromino(bag.getNext());
            }
        } catch (const std::invalid_argument &) {
            updateScore(board.removeCompleteLines(), 0);
            board.addTetromino(bag.getNext());
        }
    }
    notifyObservers();
}

void Game::dropActiveTetromino() {
    if (hasStarted && !isGameOver() && !isWinner()) {
        int dropDistance = 0;
        try {
            while (!board.activeTetroIsBellow(boardHeight - 1)) {
                board.moveActiveTetromino(Direction::DOWN);
                dropDistance++;
            }
        }
        catch (const std::exception &) {
            updateScore(board.removeCompleteLines(), dropDistance);
            board.addTetromino(bag.getNext());
        }
    }
    notifyObservers();
}

void Game::updateScore(const int linesCleared, const int dropDistance) {
    if (currentLevel * 10 <= currentLine) {
        currentLevel++;
    }
    currentLine += linesCleared;
    currentScore += getPoints(linesCleared, dropDistance);
    notifyObservers();
}

int Game::getPoints(const int lines, const int dropDistance) const {
    if (lines <= 1) {
        return (40 * lines + dropDistance) * currentLevel;
    } else {
        switch (lines) {
            case 2:
                return (100 * lines + dropDistance) * currentLevel;
            case 3:
                return (300 * lines + dropDistance) * currentLevel;
            default:
                return (1200 + lines + dropDistance) * currentLevel;
        }
    }
}

int Game::getScore() const {
    return currentScore;
}

int Game::getLines() const {
    return currentLine;
}

int Game::getLevel() const {
    return currentLevel;
}

Board const &Game::getBoard() const {
    return board;
}

Bag const &Game::getBag() const {
    return bag;
}

bool Game::isGameOver() const {
    if (targetTime != 0 && targetTime <= currentTime) {
        return true;
    }
    return board.isGameOver();
}

bool Game::isWinner() const {
    if (targetLine != 0 && targetLine <= currentLine) {
        return true;
    }
    if (targetScore != 0 && targetScore <= currentScore) {
        return true;
    }
    return false;
}

void Game::setBoardWidth(int width) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    boardWidth = width;
}

void Game::setBoardHeight(int height) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    boardHeight = height;
}

void Game::setStartLevel(int level) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    currentLevel = level;
}

void Game::setTargetLine(int line) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    targetLine = line;
}

void Game::setTargetTime(int time) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    targetTime = time;
}

void Game::setTargetScore(int score) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    targetScore = score;
}

void Game::setDifficulty(int difficulty_) {
    if (hasStarted) {
        throw std::runtime_error("You can't set Game target if it's already started");
    }
    difficulty = difficulty_;
}

Game::Game()
        : board(), bag(Bag::getInstance()), currentScore(0), currentLevel(START_LEVEL), currentLine(0), currentTime(0),
          targetLine(DEFAULT_TARGET_LINE), targetTime(DEFAULT_TARGET_TIME), targetScore(DEFAULT_TARGET_SCORE),
          difficulty(Board::DEFAULT_DIFFICULTY), boardWidth(Board::DEFAULT_WIDTH), boardHeight(Board::DEFAULT_HEIGHT) {
}
