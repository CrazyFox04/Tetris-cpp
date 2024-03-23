//
// Created by Julien Delcombel on 17/03/2024.
//

#include "GameView.h"
#include <iostream>

GameView::GameView(Game& game) : game(game) {}

void GameView::update() {
    drawGameInterface();
}

void GameView::drawGameInterface() {
    system("clear"); // Clear the terminal. !!! Not portable.

    //Display the board
    boardView.drawBoard(game.getBoard());

    // Calculate where to display the other infos
    int rightColumn = game.getBoard().getWidth() + 4;

    //Display the next tetromino
    std::cout << std::string(rightColumn, ' ');
    bagView.drawNextTetromino(game.getBag().getNextTetromino());

    //Display the score, level and lines
    std::cout << std::string(rightColumn, ' ') << "Score: " << game.getScore() << std::endl;
    std::cout << std::string(rightColumn, ' ') << "Level: " << game.getLevel() << std::endl;
    std::cout << std::string(rightColumn, ' ') << "Lines: " << game.getLines() << std::endl;
}
