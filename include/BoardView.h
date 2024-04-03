#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "Board.h"
#include "Position.h"
#include <iostream>
#include <map>

/**
 * @class BoardView
 * @brief The BoardView class
 * This class displays the board game on the console.
 */
class BoardView {
public:
    /**
     * \brief Default constructor.
     */
    BoardView() = default;

    /**
     * Draws the board game.
     * @param board The board game to draw.
     */
    void drawBoard(const Board& board) const;
private:
    /**
     * Initializes the board game with empty cells and occupied celles based on difficulty.
     * @param width The width of the board game.
     * @param height The height of the board game.
     * @param occupied The occupied cells of the board game.
     * @return The board game initialized.
     */
    std::vector<std::vector<char>>
    initializeBoard(int width, int height, const std::vector<std::vector<bool>>& occupied) const;

    /**
     * Fills the board game with char representing the tetrominos.
     * @param tetrominos The tetrominos to draw.
     * @param boardGame The board game to fill.
     * @param boardWidth The width of the board game.
     * @param boardHeight The height of the board game.
     * @param boardRefPos The reference position of the board game.
     */
    void fillBoardWithTetrominos(const std::vector<Tetromino> &tetrominos, std::vector<std::vector<char>> &boardGame,
                                 int boardWidth, int boardHeight, Position boardRefPos) const;

    /**
     * Displays the board game.
     * @param boardGame The board game to display.
     */
    void printBoard(const std::vector<std::vector<char>> &boardGame) const;
};
#endif //BOARDVIEW_H
