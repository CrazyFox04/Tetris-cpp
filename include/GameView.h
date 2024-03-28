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
const Game& game; //For now we will use the game to get the infos. Later we will use a facade
BoardView boardView;
BagView bagView;

public:
    explicit GameView(const Game& game);
    void draw();
};
#endif //GAMEVIEW_H
