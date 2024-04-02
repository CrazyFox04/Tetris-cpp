//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Direction.h"
#include "Board.h"
#include "Bag.h"

/**
 * @class GameController
 * @brief Abstract interface for controlling the Tetris Game.
 *
 * Defines the basic operations needed to control and interact with a game.
 * This interface is implemented by Game class.
 */
class GameController {
public:

    /**
     * Virtual destructor for safe polymorphic usage.
     */
    virtual ~GameController() = default;

    /**
     * Starts the game.
     * Pure virtual function overridden in Game class.
     */
    virtual void start() = 0;

    /**
     * Restarts the game.
     * Pure virtual function overridden in Game class.
     */
    virtual void restart() = 0;

    /**
     * Moves the active tetromino in the specified direction.
     * Pure virtual function overridden in Game class.
     * @param direction the direction to move the tetromino.
     */
    virtual void moveActiveTetromino(Direction2D direction) = 0;

    /**
     * Rotates the active tetromino in the specified direction.
     * Pure virtual function overridden in Game class.
     * @param rotation the rotation to apply to the tetromino.
     */
    virtual void rotateActiveTetromino(Rotation rotation) = 0;

    /**
     * Drops the active tetromino to the lowest possible position.
     * Pure virtual function overridden in Game class.
     */
    virtual void dropActiveTetromino() = 0;

    /**
     * Getter for the current game score.
     * Pure virtual function overridden in Game class.
     * @return the current score.
     */
    virtual int getScore() const = 0;

    /**
     * Getter for the number of lines cleared.
     * Pure virtual function overridden in Game class.
     * @return the number of lines cleared.
     */
    virtual int getLines() const = 0;

    /**
     * Getter for the current game level.
     * Pure virtual function overridden in Game class.
     * @return the current level.
     */
    virtual int getLevel() const = 0;

    /**
     * Getter for the current game time.
     * Pure virtual function overridden in Game class.
     * @return a const reference to the board.
     */
    virtual Board const &getBoard() const = 0;

    /**
     * Getter for the bag of tetrominos.
     * Pure virtual function overridden in Game class.
     * @return a const reference to the bag.
     */
    virtual Bag const &getBag() const = 0;

    /**
     * Checks if the game is over.
     * Pure virtual function overridden in Game class.
     * @return true if the game is over, false otherwise.
     */
    virtual bool isGameOver() const = 0;

    /**
     * Checks if the player has won the game.
     * Pure virtual function overridden in Game class.
     * @return true if the player has won, false otherwise.
     */
    virtual bool isWinner() const = 0;

    /**
 * Sets the width of the game board.
 * @param width The width of the game board.
 */
    virtual void setBoardWidth(int width) = 0;

    /**
 * Sets the height of the game board.
 * @param height The height of the game board.
 */
    virtual void setBoardHeight(int height) = 0;

    /**
 * Sets the starting level of the game.
 * @param level The starting level of the game.
 */
    virtual void setStartLevel(int level) = 0;

    /**
 * Sets the target line to clear for the game.
 * @param line The target line to clear.
 */
    virtual void setTargetLine(int targetLine) = 0;

    /**
 * Sets the target time limit for the game.
 * @param time The target time limit.
 */
    virtual void setTargetTime(int targetTime) = 0;

    /**
 * Sets the target score to achieve for the game.
 * @param score The target score to achieve.
 */
    virtual void setTargetScore(int targetScore) = 0;

    /**
 * Sets the game difficulty level.
 * @param difficulty The game difficulty level.
 */
    virtual void setDifficulty(int difficulty) = 0;

    /**
 * Checks if the game targets are valid
 * @return True if the targets are valid, false otherwise.
 */
    virtual void checkTargets() const = 0;
};

#endif //GAMECONTROLLER_H
