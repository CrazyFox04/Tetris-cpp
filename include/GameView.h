//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "Observer.h"
#include "GameController.h"
#include "BoardView.h"
#include "BagView.h"
#include <iostream>

/**
 * @class GameView
 * @brief Represents the view component in the MVC architecture for the game.
 *
 * GameView is responsible for presenting the current state of the game to the user.
 * It uses the GameController to obtain game state information and renders the game
 * board and other relevant information to the user.
 */
class GameView {
    const GameController &controller; //!< The controller of the game.
    BoardView boardView; //!< The view of the board.
    BagView bagView; //!< The view of the tetromino to come.

public:
    /**
    * Constructor for GameView.
     * Initializes the game view with a reference to the game controller.
    * @param controller_ Reference to a constant GameController used to obtain game state information.
    */
    explicit GameView(const GameController &controller_);

    /**
    * Draws the current state of the game.
    * Displays the game board, score, level, lines, and the next tetromino.
    * This method should be called in the main game loop to continuously update the game display.
    */
    void draw();

    /**
    * Displays the main menu of the game.
    * Provides options for the player to start the game.
    * This method should be called when the game is in the MAIN_MENU state.
    */
    void displayMenu();

    /**
    * Displays the game over screen.
    * Shows the player's final score and options to restart or quit the game.
    * This method should be called when the game is in the GAME_OVER state.
    */
    void displayGameOver();
};

#endif //GAMEVIEW_H
