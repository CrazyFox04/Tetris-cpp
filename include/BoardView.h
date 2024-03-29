//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "Board.h"
#include <iostream>
#include <map>

class BoardView {
    std::vector<std::vector<char>> initializeBoard(int width, int height);
    void fillBoardWithTetrominos(const std::vector<Tetromino> &tetrominos, std::vector<std::vector<char>> &boardGame,
                                 int boardWidth, int boardHeight);
    void displayBoard(const std::vector<std::vector<char>> &boardGame);
public:
    BoardView() {};
    void drawBoard(const Board& board);
};
#endif //BOARDVIEW_H
