#include "Game.h"

Game::Game(const int width, const int height, const int difficulty, const int startLevel, const int targetLine,
           const int targetTime,
           const int targetScore) : board(width, height, difficulty), bag(Bag::getInstance()), currentScore(0),
                                    currentLevel(startLevel), currentLine(0), currentTime(0), targetLine(targetLine),
                                    targetTime(targetTime), targetScore(targetScore) {
    if (width < 10 || height < 10 || difficulty < 1 || startLevel < 1 || targetLine < 1 || targetTime < 1 ||
        targetScore < 1) {
        throw std::invalid_argument("Invalid argument");
    }
}


void Game::addObserver(Observer &observer) {
    observers.emplace_back(&observer);
}

void Game::notifyObservers() {
    for (auto &observer: observers) {
        observer->update();
    }
}

void Game::removeObserver(const int pos) {
    observers.erase(observers.begin() + pos);
}

void Game::start() {
    board.addTetromino(bag.getNext());
    notifyObservers();
}

void Game::restart() {
    currentScore = 0;
    currentLevel = 1;
    currentLine = 0;
    currentTime = 0;
    start();
    notifyObservers();
}

void Game::moveActiveTetromino(Direction2D direction) {
    if (!isGameOver() && !isWinner()) {
        try {
            board.moveActiveTetromino(direction);
        }
        catch (const std::out_of_range &) {
            if (direction == Direction::DOWN) {
                int linesCleared = board.removeCompleteLines();
                updateScore(linesCleared, 0);
                board.addTetromino(bag.getNext());
            }
        } catch (const std::invalid_argument &) {
            if (direction == Direction::DOWN) {
                int linesCleared = board.removeCompleteLines();
                updateScore(linesCleared, 0);
                board.addTetromino(bag.getNext());
            }
        } catch (const std::runtime_error &) {
            // nop
        }
    }
    notifyObservers();
}

void Game::rotateActiveTetromino(const Rotation rotation) {
    if (!isGameOver() && !isWinner()) {
        try {
            board.rotateActiveTetromino(rotation);
        }
        catch (const std::out_of_range &) {
            int linesCleared = board.removeCompleteLines();
            updateScore(linesCleared, 0);
            board.addTetromino(bag.getNext());
        } catch (const std::invalid_argument &) {
            int linesCleared = board.removeCompleteLines();
            updateScore(linesCleared, 0);
            board.addTetromino(bag.getNext());
        }
    }
    notifyObservers();
}

void Game::dropActiveTetromino() {
    if (!isGameOver() && !isWinner()) {
        int dropDistance = 0;
        try {
            while (true) {
                board.moveActiveTetromino(Direction::DOWN);
                dropDistance++;
            }
        }
        catch (const std::out_of_range &) {
            int linesCleared = board.removeCompleteLines();
            updateScore(linesCleared, dropDistance);
            board.addTetromino(bag.getNext());
        } catch (const std::invalid_argument &) {
            int linesCleared = board.removeCompleteLines();
            updateScore(linesCleared, dropDistance);
            board.addTetromino(bag.getNext());
        } catch (const std::runtime_error &) {
            // nop
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

bool Game::isOccupied(const int row, const int col) const {
    return board.isOccupied(row, col);
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
    return board.isGameOver();
}

bool Game::isWinner() const {
    if (targetLine <= currentLine) {
        return true;
    }
    if (targetScore <= currentScore) {
        return true;
    }
    if (targetTime <= currentTime) {
       return true;
    }
    return false;
}