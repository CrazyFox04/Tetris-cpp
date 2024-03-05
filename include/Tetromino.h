#ifndef TETRIS_DEV4_PROJET_TETROMINO_H
#define TETRIS_DEV4_PROJET_TETROMINO_H

#include <vector>
#include "Position.h"

class Tetromino {
    int id;
    static Position refPosition;
    Position center;
    std::vector<Position> cells;

public:
    Tetromino(Tetromino& tetromino);
    Tetromino(int id, Position center, std::vector<Position> cells, int rotationState);
    void rotateClockwise();
    void rotateCounterClockwise();
    void move(int dx, int dy);
};

#endif //TETRIS_DEV4_PROJET_TETROMINO_H
