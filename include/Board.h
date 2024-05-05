#ifndef TETRIS_DEV4_PROJET_BOARD_H
#define TETRIS_DEV4_PROJET_BOARD_H

#include <vector>

#include "Position.h"
#include "Tetromino.h"
#include "Direction.h"

/**
 * @class Board
 * @brief Board class
 * Tetromino Board used in a Tetris game.
 */
class Board {
    int width; //!< Width of the board
    int height; //!< Height of the board
    std::vector<Tetromino> tetrominos; //!< Tetrominos that are in the board
    std::vector<std::vector<bool>> occupied; //!< Summary of the occupied cells in the board
    Position refPosition; //!< Reference position of the board

private:
    /**
     * \brief Initializes the board with a given difficulty.
     *
     * The board will be filled with occupied cells based on the difficulty.
     * The number of lines filled will be the difficulty percentage of the height.
     * @param difficulty [1;20] integer that will determine the fill percentage of the board
     */
    void initialize(int difficulty = 1);

    /**
     * \brief Clears a line of the board.
     *
     * Keep update the occupied and Tetrominos cells
     * @param line line number (y-axis)
     */
    void clearLine(int line);

    /**
     * Moves Direction::DOWN every lines of the board
     * @param line number of lines to push down
     */
    void moveLinesDown(int line);

    /**
     * Clears the occupied vector of the active tetromino'cells positions
     */
    void clearOccupiedForActiveTetromino();

    /**
     * Checks if tetromino's cells are in the board
     * @param tetromino tetromino to check cells
     * @return true if at least one cells is outside, false otherwise
     */
    bool isOutside(const Tetromino &tetromino) const;

    /**
 * For each cell of the active tetromino, set the corresponding cell in the occupied matrix to true.
 */
    void setOccupiedForActiveTetromino();

    /**
 * Checks if the board is too small for any of the available tetrominos.
 * The board is considered too small if any tetromino's height or length is greater than half of the board's height or width respectively.
 * @return true if the board is too small for any of the available tetrominos, false otherwise.
 * @see Bag::getAvailableTetrominos()
 */
    bool isBoardTooSmallForAvailableTetromino() const;

/**
 * Positions the given tetromino at the top of the board.
 * The tetromino is moved downwards until it is no longer outside the board.
 * If the tetromino cannot be placed within the board's height, an exception is thrown.
 * @param tetromino The tetromino to be positioned at the top of the board.
 * @throw std::invalid_argument if the board is too small to add the tetromino.
 */
    void positionTetroOnTop(Tetromino &tetromino);

    /**
 * Marks the cells occupied by a given tetromino on the board.
 * The cells of the tetromino are marked as occupied on the board.
 * @param tetromino The tetromino for which to set the occupied status.
 * @throw std::out_of_range if tetromino is outside the board; no cells are marked as occupied.
 * @throw std::invalid_argument if the tetromino is already occupied; no cells are marked as occupied.
 */
    void setOccupiedForTetromino(Tetromino &tetromino);

    /**
 * Prepare the board for a new game.
 * set game over to false, clear the board and initialize it.
 */
    void clear();

public:
    static const int DEFAULT_WIDTH = 10; //!< Default width of the board
    static const int DEFAULT_HEIGHT = 20; //!< Default height of the board
    static const int DEFAULT_DIFFICULTY = 1; //!< Default difficulty of the board
    static const int MIN_DIFFICULTY = 1; //!< Minimum difficulty of the board
    static const int MAX_DIFFICULTY = 20; //!< Maximum difficulty of the board
    static const int MIN_BOARD_WIDTH = 10; //!< Minimum width of the board
    static const int MIN_BOARD_HEIGHT = 10; //!< Minimum height of the board
    static const int MAX_BOARD_WIDTH = 30; //!< Maximum width of the board
    static const int MAX_BOARD_HEIGHT = 30; //!< Maximum height of the board

    /**
     * Constructs a Board with default width, height and difficulty.
     * \see Board(int, int, int);
     */
    Board();

    /**
     * Construct a Board with the given width, height and difficulty.
     * The Board MUST be 2 times larger and 2 times higher than the maximum of possible tetrominos
     * @param width width of the Board
     * @param height height of the Board
     * @param difficulty [1;20] integer that will determine the fill percentage of the board
     * @throw std::invalid_argument if the board is not large or higher enough
     */
    Board(int width, int height, int difficulty);

    /**
     * Adds a tetromino to the Board
     * @param tetromino tetromino to add
     * @throw std::out_of_range if the tetromino can't be placed because there isn't enough space on the board for it.
     */
    void addTetromino(Tetromino tetromino);

    /**
     * Moves the active tetromino in the given direction
     * @param direction direction to move the active tetromino. DOWN, LEFT or RIGHT
     */
    void moveActiveTetromino(Direction2D direction);

    /**
     * Rotates the active tetromino in the given direction
     * @param rotation rotation to apply to the active tetromino. CLOCKWISE or COUNTERCLOCKWISE
     */
    void rotateActiveTetromino(Rotation rotation);

    /**
     * Checks if a given position is outside the board
     * @param row to check
     * @param column to check
     * @return true if the position is outside the board, false otherwise
     */
    bool isOutside(int row, int column) const;

    /**
 * Checks if the active tetromino is below a given row
 * @param row the row to check
 * @return true if the active tetromino is below the given row, false otherwise
 */
    bool activeTetroIsBellow(int row) const;

    /**
     * Checks the value of the occupied vector at a given position
     * @param row to check
     * @param column to check
     * @return the value of the occupied vector at the given position
     */
    bool isOccupied(int row, int column) const;

    /**
     * Check that a given tetromino hasn't any of its cells already occupied on the board
     * @param tetromino tetromino to check
     * @return true if at least one cell is occupied, false otherwise
     */
    bool isOccupied(Tetromino &tetromino) const;

    /**
     * Checks if a line of the board is full of tetromino's blocks
     * @param line the line to check
     * @return false if at least one column of the line is not occupied, true otherwise
     */
    bool isLineComplete(int line) const;

    /**
     * Deletes all completed lines of the board and moves down the upper lines
     * @return the number of lines deleted
     */
    int removeCompleteLines();

    /**
     * Getter for the active tetromino
     * @return a reference to the active tetromino
     */
    const Tetromino &getActiveTetromino() const;

    /**
     * Getter for the tetrominos placed on the board
     * @return a const copy of the tetrominos vector
     */
    const std::vector<Tetromino> getTetrominos() const;

    /**
     * Getter for the width of the board
     * @return the width of the board
     */
    int getWidth() const;

    /**
     * Getter for the height of the board
     * @return the height of the board
     */
    int getHeight() const;

    /**
     * Getter for the occupied vector
     * @return a const copy of the occupied vector
     */
    const std::vector<std::vector<bool>> getOccupied() const;

    /**
     * Getter for the reference position of the board
     * @return the reference position of the board
     */
    Position getRefPosition() const;

    /**
     * Checks if the active tetromino is rotatable
     * @return true if the active tetromino is rotatable, false otherwise
     */
    bool activeTetrominoIsRotatable() const;

    Tetromino getDroppedTetro() const;
};

#endif //TETRIS_DEV4_PROJET_BOARD_H
