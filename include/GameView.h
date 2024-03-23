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

class GameView : public Observer {
Game& game; //For now we will use the game to get the infos. Later we will use a facade
BoardView boardView;
BagView bagView;

public:
    explicit GameView(Game& game);
    void update() override;
    void drawGameInterface();
};
#endif //GAMEVIEW_H
