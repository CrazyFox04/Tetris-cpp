#ifndef TETRISQTGUI_H
#define TETRISQTGUI_H
#include "GameController.h"
#include "Game.h"
#include "GameSettings.hpp"

/**
 * @class TetrisQtGUI
 * @brief The TetrisQtGUI class
 * This class is responsible for running the game.
 */
class TetrisQtGUI {
    GameSettings settings; //!< The game settings.
    std::shared_ptr<GameController> gameController; //!< The game controller.

public:
    /**
     * Construct a TetrisQtGUI.
     */
    TetrisQtGUI();

    /**
     * Main function to run the game.
     * @param argc
     * @param argv
     */
    void run(int argc, char** argv);
};
#endif //TETRISQTGUI_H
