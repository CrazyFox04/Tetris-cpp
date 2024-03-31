#include "GameView.h"

GameView::GameView(const GameController& controller_) : controller(controller_) {}

void GameView::draw() {
    //Display the board game
    boardView.drawBoard(controller.getBoard());

    //Display the score, level and lines
    std::cout << "Score: " << controller.getScore() << std::endl;
    std::cout << "Level: " << controller.getLevel() << std::endl;
    std::cout << "Lines: " << controller.getLines() << std::endl;

    //Display the next tetromino
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(controller.getBag());
    std::cout << std::endl;
}

void GameView::displayMenu() {
    std::cout << "Welcome to Tetris!" << std::endl;
    std::cout << "Press 'start' to begin the game." << std::endl;
}

void GameView::displayGameOver() {
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}
