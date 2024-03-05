//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "BoardView.h"
#include "BagView.h"

class GameView {
BoardView board;
BagView bag;
int score;
public:
    GameView(BoardView board, BagView bag, int score);
};
#endif //GAMEVIEW_H
