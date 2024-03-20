#ifndef TETRIS_DEV4_PROJET_BAG_H
#define TETRIS_DEV4_PROJET_BAG_H

#include <vector>
#include <forward_list>
#include "Tetromino.h"

class Bag {
    static Bag* instance;
    std::forward_list<Tetromino> possibleTetrominos;
    std::vector<Tetromino> bag;

    Bag();
    void shuffle();

public:
    Bag(const Bag &) = delete;
    Bag &operator=(const Bag &) = delete;

    static Bag & getInstance();
    Tetromino &getNext();
    int size();
};


#endif //TETRIS_DEV4_PROJET_BAG_H
