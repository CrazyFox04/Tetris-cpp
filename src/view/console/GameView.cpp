#include <iostream>
#include <limits>

#include "GameView.h"

#include "ApplicationTetris.h"

GameView::GameView(GameController&controller_) : controller(controller_) {
}

void GameView::draw() {
    boardView.drawBoard(controller.getBoard());
    printStats();
    printNext();
}

void GameView::printStats() const {
    std::cout << "Score: " << controller.getScore() << " - ";
    std::cout << "Level: " << controller.getLevel() << " - ";
    std::cout << "Lines: " << controller.getLines() << std::endl;
}

void GameView::printNext() const {
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(controller.getBag());
    std::cout << std::endl;
}

void GameView::displayMenu() const {
    std::cout << "Welcome to Tetris!" << std::endl;
    std::cout << "Press 'start' to begin or 'settings' to configure the game ." << std::endl;
}

void GameView::displayMessage(std::string message) const {
    std::cout << message << std::endl;
}

void GameView::displayGameOver() const {
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}

void GameView::displayVictory() const {
    std::cout << "Congratulations! You won!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}
