//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMECONTROLER_H
#define GAMECONTROLER_H

#include "Game.h"
#include "GameView.h"

class GameController {
    Game& game_;
    GameView& view_;
public:
    explicit GameController(const GameView& view, Game& game);
};
#endif //GAMECONTROLER_H
