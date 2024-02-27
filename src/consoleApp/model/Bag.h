#ifndef TETRIS_DEV4_PROJET_BAG_H
#define TETRIS_DEV4_PROJET_BAG_H

#include "Tetromino.h"

class Bag {
    Bag instance;
    Tetromino possibleTetrominos[];
    std::vector<Tetromino> bag;

private:
    Bag();
    void shuffle();

public:
    Bag getInstance();
    Tetromino & getNext();
    int size();
};

#endif //TETRIS_DEV4_PROJET_BAG_H
