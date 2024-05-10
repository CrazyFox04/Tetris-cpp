#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <thread>

#include "Game.h"

#include <thread>
#include <unistd.h>

void Game::addObserver(Observer&observer) {
    observers.emplace_back(&observer);
}

void Game::notifyObservers() {
    std::for_each(observers.begin(), observers.end(), [](std::shared_ptr<Observer>&observer) {
        observer->update();
    });
}

void Game::removeObserver(Observer&observer) {
    //    observers.erase(std::remove_if(observers.begin(), observers.end(), [&observer](std::shared_ptr<Observer>&o) {
    //        return o.get() == &observer;
    //    }), observers.end());
}

void Game::start() {
    if (gameStatus.hasStarted) {
        throw std::runtime_error("Game has already started.");
    }
    checkTargets();
    gameStatus.currentLevel = gameSettings.startLevel;
    gameStatus.hasStarted = true;
    board = Board(gameSettings.boardWidth, gameSettings.boardHeight, gameSettings.difficulty);
    tryToAddNextTetromino();
    launchAutoDown();
    notifyObservers();
}


void Game::checkTargets() const {
    if (gameSettings.boardWidth < Board::MIN_BOARD_WIDTH || gameSettings.boardHeight < Board::MIN_BOARD_HEIGHT ||
        gameSettings.boardWidth > Board::MAX_BOARD_WIDTH || gameSettings.boardHeight > Board::MAX_BOARD_HEIGHT) {
        throw std::invalid_argument("Invalid Board Size, please try again.");
    }
    if (gameSettings.difficulty < Board::MIN_DIFFICULTY || gameSettings.difficulty > Board::MAX_DIFFICULTY) {
        throw std::invalid_argument("Invalid difficulty, please try again.");
    }
    if (gameSettings.startLevel < 0) {
        throw std::invalid_argument("Invalid level, please try again.");
    }
    if (gameSettings.targetScore < 0 || gameSettings.targetTime < 0 || gameSettings.targetLine < 0) {
        throw std::invalid_argument("Invalid game parameter, please try again.");
    }
}

void Game::restart() {
    resetScore();
    gameStatus.hasStarted = false;
    gameStatus.isOver = false;
    start();
    notifyObservers();
}

void Game::resetScore() {
    gameStatus.currentScore = 0;
    gameStatus.currentLevel = gameSettings.startLevel;
    gameStatus.currentLine = 0;
    gameStatus.currentTime = 0;
}

void Game::moveActiveTetromino(Direction2D direction) {
    if (gameStatus.hasStarted && !isGameOver() && !isWinner()) {
        try {
            board.moveActiveTetromino(direction);
        }
        catch (const std::exception&) {
            if (direction == Direction::DOWN) {
                updateScore(board.removeCompleteLines(), 0);
                tryToAddNextTetromino();
            }
        }
        notifyObservers();
    }
}

void Game::rotateActiveTetromino(Rotation rotation) {
    if (gameStatus.hasStarted && !isGameOver() && !isWinner() && board.activeTetrominoIsRotatable()) {
        try {
            board.rotateActiveTetromino(rotation);
        }
        catch (const std::out_of_range&) {
            if (board.activeTetroIsBellow(gameSettings.boardHeight - 2)) {
                updateScore(board.removeCompleteLines(), 0);
                tryToAddNextTetromino();
            }
        } catch (const std::invalid_argument&) {
            // nop
        }
        notifyObservers();
    }
}

void Game::dropActiveTetromino() {
    if (gameStatus.hasStarted && !isGameOver() && !isWinner()) {
        int dropDistance = 0;
        try {
            while (!board.activeTetroIsBellow(gameSettings.boardHeight - 1)) {
                board.moveActiveTetromino(Direction::DOWN);
                dropDistance++;
            }
        }
        catch (const std::exception&) {
            updateScore(board.removeCompleteLines(), dropDistance);
            tryToAddNextTetromino();
        }
        notifyObservers();
    }
    std::cout << "Game::dropActiveTetromino" << std::endl;
}

void Game::updateScore(const int linesCleared, const int dropDistance) {
    if (gameStatus.currentLevel * 10 <= gameStatus.currentLine) {
        gameStatus.currentLevel++;
    }
    gameStatus.currentLine += linesCleared;
    gameStatus.currentScore += getPoints(linesCleared, dropDistance);
    notifyObservers();
}

int Game::getPoints(const int lines, const int dropDistance) const {
    if (lines <= 1) {
        return (40 * lines + dropDistance) * gameStatus.currentLevel;
    }
    switch (lines) {
        case 2:
            return (100 * lines + dropDistance) * gameStatus.currentLevel;
        case 3:
            return (300 * lines + dropDistance) * gameStatus.currentLevel;
        default:
            return (1200 + lines + dropDistance) * gameStatus.currentLevel;
    }
}

int Game::getScore() const {
    return gameStatus.currentScore;
}

int Game::getLines() const {
    return gameStatus.currentLine;
}

int Game::getLevel() const {
    return gameStatus.currentLevel;
}

Board const& Game::getBoard() const {
    return board;
}

Bag const& Game::getBag() const {
    return bag;
}

bool Game::isGameOver() const {
    if (gameStatus.currentTime != 0 && gameSettings.targetTime <= gameStatus.currentTime) {
        return true;
    }
    return gameStatus.isOver;
}

bool Game::isWinner() const {
    if (gameSettings.targetLine != 0 && gameSettings.targetLine <= gameStatus.currentLine) {
        return true;
    }
    if (gameSettings.targetScore != 0 && gameSettings.targetScore <= gameStatus.currentScore) {
        return true;
    }
    return false;
}

Game::Game() : bag(Bag::getInstance()) {
}

Game::Game(GameSettings gameSettings_) : bag(Bag::getInstance()), gameSettings(gameSettings_), autoDownThread(false, std::thread()) {
}

void Game::tryToAddNextTetromino() {
    try {
        board.addTetromino(bag.getNext());
        gameStatus.numberOfTetrominosPut++;
    }
    catch (std::out_of_range&e) {
        gameStatus.isOver = true;
    }
}

Tetromino Game::getDroppedTetro() {
    return board.getDroppedTetro();
}

void Game::launchAutoDown() {
    if (autoDownThread.second.joinable()) {
        autoDownThread.first = false;
        autoDownThread.second.join();
    }
    autoDownThread.first = true;
    autoDownThread.second = std::thread([this]() {
        while (!isGameOver() && !isWinner() && autoDownThread.first) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 / (gameStatus.currentLevel + 1)));
            try {
                board.moveActiveTetromino(Direction::DOWN);
            }
            catch (const std::exception&) {
                updateScore(board.removeCompleteLines(), 0);
                tryToAddNextTetromino();
            }
            notifyObservers();
        }
    });
}

int Game::getNumberOfTetrominoPut() {
    return gameStatus.numberOfTetrominosPut;
}

Tetromino Game::getBeforeLastTetromino() const {
    return board.getTetrominos().at(board.getTetrominos().size() - 2);
}

int Game::getTime() const {
    return gameStatus.currentTime;
}