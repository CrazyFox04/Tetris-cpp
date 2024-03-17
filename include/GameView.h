//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "Observer.h"
#include "BoardView.h"
#include "BagView.h"

class GameView : public Observer {
BoardView boardView;
BagView bagView;
int score;
int level;
int lines;

public:
    GameView(BoardView board, BagView bag, int score);
    void update() override;
    void clearScreen();
    void displayInfos();
};
#endif //GAMEVIEW_H
