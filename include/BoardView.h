//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "Board.h"
#include "Position.h"
#include <iostream>
#include <map>

/**
 * @class BoardView
 * @brief The BoardView class
 * This class is responsible for drawing the board game.
 */
class BoardView {
    /**
     * Initializes the board game with empty cells.
     * @param width The width of the board game.
     * @param height The height of the board game.
     * @return The board game initialized.
     */
    std::vector<std::vector<char>> initializeBoard(int width, int height, const std::vector<std::vector<bool>> &occupied);

    /**
     * Fills the board game with char representing the tetrominos.
     * @param tetrominos The tetrominos to draw.
     * @param boardGame The board game to fill.
     * @param boardWidth The width of the board game.
     * @param boardHeight The height of the board game.
     * @param boardRefPos The reference position of the board game.
     */
    void fillBoardWithTetrominos(const std::vector<Tetromino> &tetrominos, std::vector<std::vector<char>> &boardGame,
                                 int boardWidth, int boardHeight, Position boardRefPos);

    /**
     * Displays the board game.
     * @param boardGame The board game to display.
     */
    void displayBoard(const std::vector<std::vector<char>> &boardGame);
public:
    /**
     * \brief Default constructor.
     */
    BoardView() = default;

    /**
     * Draws the board game.
     * @param board The board game to draw.
     */
    void drawBoard(const Board& board);
};
#endif //BOARDVIEW_H
