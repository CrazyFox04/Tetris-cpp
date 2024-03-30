//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "Observer.h"
#include "BoardView.h"
#include "BagView.h"
#include "Game.h"
#include <iostream>

class GameView {
const GameController& controller;
BoardView boardView;
BagView bagView;

public:
    explicit GameView(const GameController& controller_);
    void draw();
    void displayMenu();
    void displayGameOver();
};
#endif //GAMEVIEW_H
