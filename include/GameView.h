#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <string>

#include "GameController.h"
#include "BoardView.h"
#include "BagView.h"


/**
 * @class GameView
 * @brief Represents the view component in the MVC architecture for the game.
 *
 * GameView is responsible for presenting the current state of the game to the user.
 * It uses the GameController to obtain game state information and renders the game
 * board and other relevant information to the user.
 */
class GameView {
    GameController &controller; //!< The controller of the game.
    BoardView boardView; //!< The view of the board.
    BagView bagView; //!< The view of the tetromino to come.

    /**
     * Prints the current score, level, and number of lines cleared.
     */
    void printStats() const;

    /**
     * Prints the next tetromino to come.
     */
    void printNext() const;

public:
    /**
    * Constructor for GameView.
     * Initializes the game view with a reference to the game controller.
    * @param controller_ Reference to a constant GameController used to obtain game state information.
    */
    explicit GameView(GameController &controller_);

    /**
    * Draws the current state of the game.
    * Displays the game board, score, level, lines, and the next tetromino.
    * This method should be called in the main game loop to continuously update the game display.
    */
    void draw();

    /**
    * Displays the main menu of the game.
    * Offers the choice to start the game or configure the game settings.
    * This method should be called when the game is in the MAIN_MENU state.
    */
    void displayMenu() const;

    /**
     * Displays the different settings of the game to the player
     * and collects the player's input to configure the game.
     */
    void displaySettings();

    /**
    * Displays the game over screen.
    * Shows the player's final score and options to restart or quit the game.
    */
    void displayGameOver() const;

    /**
     * Displays the victory screen.
     * Shows the player's final score and options to restart or quit the game.
     */
    void displayVictory() const;

    /**
     * Displays a message to the player.
     * @param message The message to display.
     */
    void displayMessage(std::string message) const;
};

#endif //GAMEVIEW_H
