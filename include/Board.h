#ifndef TETRIS_DEV4_PROJET_BOARD_H
#define TETRIS_DEV4_PROJET_BOARD_H

#include <vector>
#include "Tetromino.h"
#include "Direction.hpp"

class Board {
    int width;
    int height;
    std::vector<Tetromino> tetrominos;
    bool occupied[1][1];
    Position refPosition;

private:
    void initialize(int difficulty = 0);
    void clearLine(int line);
    void moveLinesDown(int line);

public:
    Board();
    Board(int width, int height, int difficulty); // difficulty will determinate the percentage of occupied cells
    void addTetromino(Tetromino tetromino);
    void moveActiveTetromino(Direction direction);
    void rotateActiveTetromino(Direction direction);
    bool isOutside(int row, int column);
    bool isOccupied(int row, int column);
    bool isLineComplete(int line);
    int removeCompleteLines();
    bool isGameOver();
};

#endif //TETRIS_DEV4_PROJET_BOARD_H
