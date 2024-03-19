//
// Created by Julien Delcombel on 07/03/2024.
//

#include "Game.h"

Game::Game() : gameControler(new GameControler()), bag(Bag::getInstance()), score(0), level(1), gameOver(false) {
    board = Board();
    initializeCommands();
}

/* We canno't use play function cause we have to continue implementation
void Game::play() {
    initializeCommands();
    std::string input;
    std::cin >> input;

    invoker.execute(input);

    if (gameOver) {
        return;
    }

    if (!board.canTetroMove(Direction::DOWN)) {
        int linesCleared = board.removeCompleteLines();
        updateScore(linesCleared, 0);
        board.addTetromino(Bag::getInstance().getNext());
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
}*/

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
    board.addTetromino(Bag::getInstance().getNext());
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
