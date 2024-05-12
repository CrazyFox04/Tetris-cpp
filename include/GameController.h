#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Observable.h"
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
class GameController : public Observable {
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
    virtual Board const& getBoard() const = 0;

    /**
     * Getter for the bag of tetrominos.
     * Pure virtual function overridden in Game class.
     * @return a const reference to the bag.
     */
    virtual Bag const& getBag() const = 0;

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
 * Checks if the game targets are valid
 * @return True if the targets are valid, false otherwise.
 */
    virtual void checkTargets() const = 0;

    virtual void addObserver(Observer&observer) = 0;

    virtual void removeObserver(Observer&observer) = 0;

    virtual Tetromino getDroppedTetro() = 0;

    virtual Tetromino getBeforeLastTetromino() const = 0;

  virtual int getTime() const = 0;
};

#endif //GAMECONTROLLER_H
