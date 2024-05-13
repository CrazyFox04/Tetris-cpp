#ifndef TETRISQTGUI_H
#define TETRISQTGUI_H
#include "GameController.h"
#include "Game.h"
#include "GameSettings.hpp"


class TetrisGameOver;
class TetrisView;
class TetrisConfiguration;
/**
 * @class TetrisQtGUI
 * @brief The TetrisQtGUI class
 * This class is responsible for running the game.
 */
class TetrisQtGUI {
    GameSettings settings; //!< The game settings.
    std::shared_ptr<GameController> gameController; //!< The game controller.
    TetrisConfiguration* tetris_configuration; //!< The configuration window.
    TetrisView* tetris_view; //!< The game view.
    TetrisGameOver* tetris_game_over; //!< The game over window.

    void configureEndOfConfiguration();
    void configureEndOfGame();
    void configureEndOfGameOver();
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
