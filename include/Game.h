#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include <vector>
#include <memory>
#include <thread>
#include <mutex>

#include "GameController.h"
#include "Observable.h"
#include "Observer.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include "GameSettings.hpp"
#include "GameStatus.hpp"

/**
 * @class Game
 * @brief Main game controller class implementing game logic and observer pattern.
 *
 * The Game class controls the game state, including the game board, score, levels, and time.
 * It implements the GameController interface for handling game actions and the Observable interface
 * for observer pattern functionality, allowing communication with various observers.
 */
class Game : public GameController {
    std::vector<Observer*> observers; ///< List of observers to notify on state change.
    Board board; ///< The game board.
    Bag&bag; ///< Reference to a Bag containing game pieces.
    GameSettings gameSettings; ///< Game settings. Immutable when a game has started
    GameStatus gameStatus; ///< Game stats of the current game
    std::pair<bool, std::thread> autoDownThread; ///< Thread for automatic downward movement of the active tetromino
    std::pair<bool, std::thread> countDownThread; ///< Thread for the countdown timer
    std::mutex mutex; ///< Mutex for thread safety.

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

    /**
     * Tries to add the next tetromino to the board.
     * If the tetromino can't be added, the game is over.
     */
    void tryToAddNextTetromino();

    /**
     * @brief Launches the auto down thread for moving the tetromino down periodically.
     */
    void launchAutoDown();

    /**
     * @brief Gets the time between automatic downward movements based on the current level.
     * @param level The current game level.
     * @return Time in milliseconds between automatic downward movements.
     */
    static int getTimeBetweenDown(int level);

public:
    static constexpr int MAX_START_LEVEL = 20; ///< Maximum start level for the game.

    /**
     * @brief Constructs a Game object.
     */
    Game();

    /**
     * @brief Destructor for the Game object.
     */
    ~Game();

    /**
     * Constructs a Game with default parameters.
     * @param gameSettings game's settings
     */
    Game(GameSettings gameSettings);

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

    /**
     * @brief Notifies all observers of a state change.
     */
    void notifyObservers() override;

    /**
     * @brief Adds an observer to the list.
     * @param observer The observer to add.
     */
    void addObserver(Observer* observer) override;

    /**
     * @brief Removes an observer from the list.
     * @param observer The observer to remove.
     */
    void removeObserver(Observer* observer) override;

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
    const Board& getBoard() const override;

    /**
     * Getter for the bag of tetrominos.
     * @return Constant reference to the bag.
     */
    const Bag& getBag() const override;

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
     * Checks if the game targets are valid
     * @return True if the targets are valid, false otherwise.
     */
    void checkTargets() const override;

    /**
     * @brief Gets the tetromino that has been dropped.
     * @return The dropped tetromino.
     */
    Tetromino getDroppedTetro() override;

    /**
     * @brief Gets the tetromino before the last one.
     * @return The tetromino before the last one.
     */
    Tetromino getBeforeLastTetromino() const override;

    /**
     * @brief Gets the current game time.
     * @return The current game time.
     */
    int getTime() const override;

    /**
     * @brief Launches the countdown timer thread.
     */
    void launchCountDown();
};


#endif //TETRIS_DEV4_PROJET_GAME_H
