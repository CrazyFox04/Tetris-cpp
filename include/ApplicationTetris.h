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
    GameSettings gameSettings;
    std::shared_ptr<GameController> gameController; //!< Controller interface for the game
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

    /**
    * Asks the user for an integer input within a specified range.
    * This method displays the given prompt, validates the input to ensure it's an integer
    * within the specified range, and handles any input errors.
    *
    * @param prompt The message to display to the user.
    * @param min The minimum allowable value.
    * @param max The maximum allowable value.
    * @return The validated integer input from the user.
    */
    int askForInt(const std::string&prompt, int min, int max);

    /**
     * Ask the user for custom game settings.
     */
    void customSettings();
};

#endif //TETRIS_APPLICATIONTETRIS_H
