//
// Created by Julien Delcombel on 17/03/2024.
//

#include "GameView.h"
#include <iostream>

GameView::GameView(BoardView board, BagView bag, int initialScore)
    : boardView { board }, bagView { bag }, score { initialScore } {}

void GameView::update() {
    clearScreen();
    boardView.display();
    displayInfos();
    bagView.display();
}

void GameView::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void GameView::displayInfos() {
    std::cout << "Score: " << score << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Lines: " << lines << std::endl;
}