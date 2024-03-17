//
// Created by Julien Delcombel on 07/03/2024.
//

#include <iostream>
#include "Game.h"

Game::Game() : gameControler(std::make_unique<GameControler>()), score(0), level(1), gameOver(false), invoker() {
    board = Board();
    bag = Bag::getInstance();
    initializeCommands();
}

Game:: ~Game() {
    delete gameControler;
    delete invoker;
}

void Game::play() {
    initializeCommands();
    char input;
    std::cin >> input;

    invoker.execute(input);

    if (gameOver) {
        return;
    }

    if (!board.canTetroMove(Direction::DOWN)) {
        int linesCleared = board.removeCompleteLines();
        updateScore(linesCleared, 0);
        board.addTetromino(bag.getNext());
    }
}
// Pour avancer. Je ne me suis pas du tout pencher sur command pattern
void initizaCommands() {
    invoker.addNewCommand("q", new MoveLeftCommand(gameControler));
    invoker.addNewCommand("d", new MoveRightCommand(gameControler));
    invoker.addNewCommand("s", new MoveDownCommand(gameControler));
    invoker.addNewCommand("z", new RotateClockwiseCommand(gameControler));
    invoker.addNewCommand("a", new RotateCounterClockwiseCommand(gameControler));
    invoker.addNewCommand("e", new DropCommand(gameControler));
}

void Game::moveActiveTetromino(Direction2D direction) {
    if (!gameOver) {
        board.moveActiveTetromino(direction);
    }
    notifyObservers();
}

void Game::rotateActiveTetromino(Rotation rotation) {
    if (!gameOver) {
        board.rotateActiveTetromino(rotation);
    }
    notifyObservers();
}

void Game::dropActiveTetromino() {
    int dropDistance = 0;

    while (true) {
        auto originalPosition = board.getActiveTetromino().get_ref_position();

        board.moveActiveTetromino(Direction::DOWN);
        if (originalPosition == board.getActiveTetromino().get_ref_position()) {
            break;
        }
        dropDistance++;
    }
    int linesCleared = board.removeCompleteLines();
    updateScore(linesCleared, dropDistance);
    board.addTetromino(bag.getNext());
    notifyObservers();
}

void Game::updateScore(int linesCleared, int dropDistance) {
    score += getPoints(linesCleared, dropDistance);
    notifyObservers();
}

void Game::updateLevel() {
    level++;
    notifyObservers();
}

int Game::getPoints(int lines, int dropDistance) const {
    switch (lines) {
        case 1: return (40 * lines + dropDistance) * level;
        case 2: return (100 * lines + dropDistance) * level;
        case 3: return (300 * lines + dropDistance) * level;
        case 4: return (1200 + lines + dropDistance) * level;
        default: return dropDistance * level;
    }
}