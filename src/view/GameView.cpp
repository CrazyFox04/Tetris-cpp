#include "GameView.h"

GameView::GameView(const Game& game) : game(game) {}

void GameView::draw() {
    //Display the board game
    boardView.drawBoard(game.getBoard());

    //Display the score, level and lines
    std::cout << "Score: " << game.getScore() << std::endl;
    std::cout << "Level: " << game.getLevel() << std::endl;
    std::cout << "Lines: " << game.getLines() << std::endl;

    //Display the next tetromino
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(game.getBag());
    std::cout << std::endl;
}

void GameView::displayMenu() {
    std::cout << "Welcome to Tetris!" << std::endl;
    std::cout << "Press 'start' to begin the game." << std::endl;
}

void GameView::displayGameOver() {
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score: " << game.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}
