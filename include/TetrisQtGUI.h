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
    bool wantToExit; //!< The exit flag.
    GameSettings settings; //!< The game settings.
    std::shared_ptr<GameController> gameController; //!< The game controller.
    TetrisConfiguration* tetris_configuration; //!< The configuration window.
    TetrisView* tetris_view; //!< The game view.
    TetrisGameOver* tetris_game_over; //!< The game over window.

    /**
     * @brief Configures the end of the configuration window.
     *
     * This method connects signals and slots to handle the end of the configuration phase.
     * It starts the game if the user proceeds, or exits the application if the user wants to exit.
     */
    void configureEndOfConfiguration();

    /**
     * @brief Configures the end of the game view.
     *
     * This method connects signals and slots to handle the end of the game phase.
     * It transitions to the game over screen when the game view is destroyed.
     */
    void configureEndOfGame();

    /**
    * @brief Configures the end of the game over window.
    *
    * This method connects signals and slots to handle the end of the game over phase.
    * It either restarts the configuration window or exits the application based on user input.
    */
    void configureEndOfGameOver();

public:
    /**
     * @brief Constructs a TetrisQtGUI object.
     */
    TetrisQtGUI();

    /**
     * @brief Runs the TetrisQtGUI application.
     * @param argc Argument count.
     * @param argv Argument values.
     */
    void run(int argc, char** argv);
};
#endif //TETRISQTGUI_H
