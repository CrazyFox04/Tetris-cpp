#ifndef TETRIS_DEV4_PROJET_BOARD_H
#define TETRIS_DEV4_PROJET_BOARD_H

#include <vector>
#include "Tetromino.h"
#include "Direction.h"

/**
 * Tetromino Board used in a Tetris game.
 */
class Board {
    int width; //!< Width of the board
    int height; //!< Height of the board
    bool gameOver; //!< State of the board
    std::vector<Tetromino> tetrominos; //!< Tetrominos that are in the board
    std::vector<std::vector<bool>> occupied; //!< Summary of the occupied cells in the board
    Position refPosition; //!< Reference position of the board

private:
    /**
     * \brief Initialize the board with a given difficulty.
     *
     * The board will be filled with occupied cells based on the difficulty.
     * The number of lines filled will be the difficulty percentage of the height.
     * @param difficulty [1;20] integer that will determine the fill percentage of the board
     */
    void initialize(int difficulty = 1);

    /**
     * \brief Clear a line of the board.
     *
     * Keep update the occupied and Tetrominos cells
     * @param line line number (y-axis)
     */
    void clearLine(int line);

    /**
     * Move Direction::DOWN every lines of the board
     * @param line number of lines to push down
     */
    void moveLinesDown(int line);

    /**
     * Clear the occupied vector of the active tetromino'cells positions
     */
    void clearOccupiedForActiveTetromino();

    /**
     * Check if tetromino's cells are in the board
     * @param tetromino tetromino to check cells
     * @return true if at least one cells is outside, false otherwise
     */
    bool isOutside(Tetromino& tetromino) const;
    void setOccupiedActiveTetromino();

public:
    /**
     * Cronstruct a 10 by 20 board with a difficulty of 20
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
    Board(int width, int height, int difficulty); // difficulty will determinate the percentage of occupied cells

    /**
     * Add a tetromino to the Board
     * @param tetromino
     */
    void addTetromino(Tetromino tetromino);

    void moveActiveTetromino(Direction2D direction);

    void rotateActiveTetromino(Rotation rotation);

    bool isOutside(int row, int column) const;

    bool isOccupied(int row, int column) const;

    bool isLineComplete(int line) const;

    int removeCompleteLines();

    bool isGameOver() const;

    Tetromino& getActiveTetromino();

    const std::vector<Tetromino> getTetrominos() const;

    int getWidth() const;

    int getHeight() const;

    const std::vector<std::vector<bool>> getOccupied() const;

    Position getRefPosition() const;
    void clear();
};

#endif //TETRIS_DEV4_PROJET_BOARD_H
