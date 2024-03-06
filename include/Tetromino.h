#ifndef TETRIS_DEV4_PROJET_TETROMINO_H
#define TETRIS_DEV4_PROJET_TETROMINO_H

#include <vector>
#include "Position.h"

class Tetromino {
    int id;
    Position refPosition;
    std::vector<Position> cells;

public:
    Tetromino(int id, Position center, std::vector<Position> cells);
    int get_id() const;
    Position get_ref_position() const;
    std::vector<Position> get_relative_cells() const;
    void rotateClockwise();
    void rotateCounterClockwise();
    void move(int dx, int dy);
};

#endif //TETRIS_DEV4_PROJET_TETROMINO_H
