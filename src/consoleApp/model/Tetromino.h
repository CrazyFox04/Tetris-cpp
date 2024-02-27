#ifndef TETRIS_DEV4_PROJET_TETROMINO_H
#define TETRIS_DEV4_PROJET_TETROMINO_H

#include <vector>
#include "Position.h"

class Tetromino {
    int id;
    Position refPosition;
    Position center;
    std::vector<Position> cells;

public:
    Tetromino();
    Tetromino(int id);
    void rotateClockwise();
    void rotateCounterClockwise();
    void move(int dx, int dy);
};

#endif //TETRIS_DEV4_PROJET_TETROMINO_H
