#ifndef TETRIS_APPLICATIONTETRIS_H
#define TETRIS_APPLICATIONTETRIS_H

#include "Game.h"
#include "GameController.h"
#include "Invoker.h"
#include "GameView.h"

/**
 * @class ApplicationTetris
 * @brief Main application class for the Tetris game.
 *
 * ApplicationTetris sets up and runs the Tetris game, managing the game loop,
 * handling user input, and orchestrating the game view and game controller.
 */
class ApplicationTetris {
    std::unique_ptr<GameController> gameController; //!< Controller interface for the game
    Invoker invoker; //!< Command Invoker for the game
    GameView gameView; //!< View component for rendering the game

    /**
     * Initialize the commands associated with various game actions.
     * This method sets up commands and associates them with the specific game states

     */
    void initializeCommands();

    /**
     * Handle user input during the game.
     * This method reads user input and executes associated command
     */
    void handleInput();

public:
    /**
     * Constructor for ApplicationTetris.
     * Initializes the game, controller, view, and sets up commands.
     */
    ApplicationTetris();

    /**
     * Run the Tetris game loop.
     * This method keeps the game running, updating the view and handling user input
     * until the game is over.
     */
    void run();
};

#endif //TETRIS_APPLICATIONTETRIS_H
