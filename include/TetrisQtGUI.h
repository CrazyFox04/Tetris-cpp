//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISQTGUI_H
#define TETRISQTGUI_H
#include "GameController.h"
#include "GameSettings.hpp"


class TetrisQtGUI {
    GameSettings settings;
    std::unique_ptr<GameController> gameController;

    void showMainMenu(int argc, char** argv);

public:
    TetrisQtGUI();
    int run(int argc, char** argv);
};
#endif //TETRISQTGUI_H
