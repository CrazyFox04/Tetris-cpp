//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISQTGUI_H
#define TETRISQTGUI_H
#include "GameController.h"
#include "Game.h"
#include "GameSettings.hpp"


class TetrisQtGUI {
    GameSettings settings;
    std::shared_ptr<GameController> gameController;

public:
    TetrisQtGUI();
    void run(int argc, char** argv);
};
#endif //TETRISQTGUI_H
