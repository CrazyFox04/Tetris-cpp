#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include "GameController.h"
#include <vector>
#include "Observable.h"
#include "Observer.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include <memory>

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

private:

    /**
    * Updates the game score based on the number of lines cleared and the drop distance.
    * @param linesCleared The number of lines cleared in the move.
    * @param dropDistance The distance the tetromino dropped.
    */
    void updateScore(int linesCleared, int dropDistance);
    void updateLevel();

    /**
    * Calculates the points based on the number of lines cleared and the drop distance.
    * @param lines The number of lines cleared.
    * @param dropDistance The distance the tetromino dropped.
    * @return Calculated points.
    */
    int getPoints(int lines, int dropDistance) const;

    //TODO: necessaire?
    void initializeCommands();
public:
    /**
    * Constructs a new game with the specified parameters.
    * Throws an exception if parameters are invalid.
    * @param width Width of the game board.
    * @param height Height of the game board.
    * @param difficulty Difficulty level of the game.
    * @param startLevel Initial level of the game.
    * @param targetLine Line target for winning the game.
    * @param targetTime Time target for winning the game.
    * @param targetScore Score target for winning the game.
    */
    Game(int width, int height, int difficulty, int startLevel, int targetLine, int targetTime, int targetScore);

    /**
 * Starts the game, initiating the first tetromino from the bag.
     * Overrides GameController::start().
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
    void moveActiveTetromino(Direction2D direction);

    /**
    * Rotates the active tetromino in the specified direction.
    * @param rotation The direction of rotation.
    */
    void rotateActiveTetromino(Rotation rotation);

    /**
    * Drops the active tetromino to the lowest possible position.
    * Calls dropActiveTetromino() until the tetromino can no longer move downwards.
    */
    void dropActiveTetromino();

    //TODO: necessaire?
    bool isOccupied(int row, int col) const;

    
    void notifyObservers() override;
    void addObserver(Observer& observer) override;
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
    Board const & getBoard() const override;

    /**
     * Getter for the bag of tetrominos.
     * @return Constant reference to the bag.
     */
    Bag const & getBag() const override;

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
};


#endif //TETRIS_DEV4_PROJET_GAME_H
