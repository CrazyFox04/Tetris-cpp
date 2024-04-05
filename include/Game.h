#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include <vector>
#include <memory>

#include "GameController.h"
#include "Observable.h"
#include "Observer.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"

/**
 * @class Game
 * @brief Main game controller class implementing game logic and observer pattern.
 *
 * The Game class controls the game state, including the game board, score, levels, and time.
 * It implements the GameController interface for handling game actions and the Observable interface
 * for observer pattern functionality, allowing communication with various observers.
 *
 * NOTE :: Observer/Observable pattern will be implemented truly in the final GUI iteration.
 */
class Game : public Observable, public GameController {
    std::vector<std::shared_ptr<Observer>> observers; ///< List of observers to notify on state change.
    Board board; ///< The game board.
    Bag &bag; ///< Reference to a Bag containing game pieces.
    int currentScore; ///< Current score of the game.
    int currentLevel; ///< Current level of the game.
    int currentLine; ///< Current cleared lines in the game.
    int currentTime; ///< Current time elapsed in the game.
    int targetLine; ///< Target line to clear.
    int targetTime; ///< Target time limit for the game.
    int targetScore; ///< Target score to achieve.
    int difficulty; ///< Board's Game difficulty level.
    bool hasStarted; ///< Flag indicating if the game has started.
    int boardWidth; ///< Width of the game board.
    int boardHeight; ///< Height of the game board.
    static const int START_LEVEL = 1; ///< Default starting level of the game.
    static const int DEFAULT_TARGET_LINE = 0; ///< Default target line to clear.
    static const int DEFAULT_TARGET_TIME = 0; ///< Default target time limit.
    static const int DEFAULT_TARGET_SCORE = 0; ///< Default target score to achieve.

private:

    /**
    * Updates the game score based on the number of lines cleared and the drop distance.
    * @param linesCleared The number of lines cleared in the move.
    * @param dropDistance The distance the tetromino dropped.
    */
    void updateScore(int linesCleared, int dropDistance);

    /**
    * Calculates the points based on the number of lines cleared and the drop distance.
    * @param lines The number of lines cleared.
    * @param dropDistance The distance the tetromino dropped.
    * @return Calculated points.
    */
    int getPoints(int lines, int dropDistance) const;

    /**
 * Resets the game score and stats
 */
    void resetScore();

public:
    /**
     * Constructs a Game with default parameters.
     */
    Game();

    /**
  * Starts the game.
  * @throws std::invalid_argument if the game parameters are invalid.
  * @throws std::runtime_error if the game has already started.
  */
    void start() override;

    /**
    * Restarts the game, resetting the game state and beginning a new one.
     * Overrides GameController::restart().
    */
    void restart() override;

    /**
    * Moves the active tetromino in the specified direction.
    * Handles logic for game continuation or termination based on the move result.
    * @param direction The direction to move the active tetromino.
    */
    void moveActiveTetromino(Direction2D direction) override;

    /**
    * Rotates the active tetromino in the specified direction.
    * @param rotation The direction of rotation.
    */
    void rotateActiveTetromino(Rotation rotation) override;

    /**
    * Drops the active tetromino to the lowest possible position.
    * Calls dropActiveTetromino() until the tetromino can no longer move downwards.
    */
    void dropActiveTetromino() override;

    void notifyObservers() override;

    void addObserver(Observer &observer) override;

    void removeObserver(int pos) override;

    /**
     * Getter for the current game score.
     * @return The current game score.
     */
    int getScore() const override;

    /**
     * Getter for the number of lines cleared.
     * @return The number of lines cleared.
     */
    int getLines() const override;

    /**
     * Getter for the current game level.
     * @return The current game level.
     */
    int getLevel() const override;

    /**
     * Getter for the game board
     * @return Constant reference to the board.
     */
    const Board &getBoard() const override;

    /**
     * Getter for the bag of tetrominos.
     * @return Constant reference to the bag.
     */
    const Bag &getBag() const override;

    /**
     * Checks if the game is over.
     * @return True if the game is over, false otherwise.
     */
    bool isGameOver() const override;

    /**
     * Checks if the game has been won based on target lines, score or time
     * @return True if the player has won, false otherwise.
     */
    bool isWinner() const override;

    /**
     * Sets the width of the game board.
     * @param width The width of the game board.
     * @throw std::runtime_error if the game has already started.
     */
    void setBoardWidth(int width) override;

    /**
     * Sets the height of the game board.
     * @param height The height of the game board.
     * @throw std::runtime_error if the game has already started.
     */
    void setBoardHeight(int height) override;

    /**
     * Sets the starting level of the game.
     * @param level The starting level of the game.
     * @throw std::runtime_error if the game has already started.
     */
    void setStartLevel(int level) override;

    /**
     * Sets the target line to clear for the game.
     * @param line The target line to clear.
     * @throw std::runtime_error if the game has already started.
     */
    void setTargetLine(int line) override;

    /**
     * Sets the target time limit for the game.
     * @param time The target time limit.
     * @throw std::runtime_error if the game has already started.
     */
    void setTargetTime(int time) override;

    /**
     * Sets the target score to achieve for the game.
     * @param score The target score to achieve.
     * @throw std::runtime_error if the game has already started.
     */
    void setTargetScore(int score) override;

    /**
     * Sets the game difficulty level.
     * @param difficulty The game difficulty level.
     * @throw std::runtime_error if the game has already started.
     */
    void setDifficulty(int difficulty) override;

    /**
     * Checks if the game targets are valid
     * @return True if the targets are valid, false otherwise.
     */
    void checkTargets() const override;
};


#endif //TETRIS_DEV4_PROJET_GAME_H
