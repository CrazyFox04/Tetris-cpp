#ifndef TETRIS_DEV4_PROJET_BOARD_H
#define TETRIS_DEV4_PROJET_BOARD_H

#include <vector>
#include "Tetromino.h"
#include "Direction.h"

class Board {
    int width;
    int height;
    std::vector<Tetromino> tetrominos;
    std::vector<std::vector<bool>> occupied;
    Position refPosition;

private:
    void initialize(int difficulty = 0);
    void clearLine(int line);
    void moveLinesDown(int line);

public:
    Board();
    Board(int width, int height, int difficulty); // difficulty will determinate the percentage of occupied cells
    void addTetromino(const Tetromino& tetromino);
    void moveActiveTetromino(Direction2D direction);
    void rotateActiveTetromino(Rotation rotation);
    bool isOutside(int row, int column) const;
    bool isOccupied(int row, int column) const;
    bool isLineComplete(int line) const;
    int removeCompleteLines();
    bool isGameOver();
    Tetromino& getActiveTetromino();
};

#endif //TETRIS_DEV4_PROJET_BOARD_H
