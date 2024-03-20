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
    void set_relative_cells(const std::vector<Position>& newCells);
};
bool operator==(const Tetromino &Tetromino1, const Tetromino &Tetromino2);

#endif //TETRIS_DEV4_PROJET_TETROMINO_H
