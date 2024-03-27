#include "GameView.h"

GameView::GameView(const Game& game) : game(game) {}

void GameView::draw() const {
    //Display the board game
    boardView.drawBoard(game.getBoard()); //getBoard() nécessaire

    //Display the score, level and lines
    std::cout << "Score: " << game.getScore() << std::endl;
    std::cout << "Level: " << game.getLevel() << std::endl;
    std::cout << "Lines: " << game.getLines() << std::endl;

    //Display the next tetromino
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(game.getBag());
    std::cout << std::endl;
}
