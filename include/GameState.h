#ifndef TETRIS_GAMESTATE_H
#define TETRIS_GAMESTATE_H

/**
 * @enum GameState
 * @brief Represents the different states a game can be in.
 *
 * This enumeration is used to define the current state of the game.
 * It is useful for determining the available commands that can be executed in each state.
 */
enum class GameState {
    MAIN_MENU, ///< The game is at the main menu. Certain commands might be restricted in this state.
    PLAYING,   ///< The game is in progress. Most game-related commands are available in this state.
    END_GAME  ///< The game has ended. Commands are limited to restarting or quitting the game.
};

#endif //TETRIS_GAMESTATE_H
