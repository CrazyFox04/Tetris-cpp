#ifndef TETRIS_DEV4_PROJET_BAG_H
#define TETRIS_DEV4_PROJET_BAG_H

#include <vector>
#include <forward_list>
#include "Tetromino.h"

class Bag {
    static Bag* instance;
    std::vector<Tetromino> possibleTetrominos;
    std::vector<Tetromino> bag;
    void addTetrominosToBag();
    Bag();
    void shuffle();

public:
    Bag(const Bag &) = delete;
    Bag &operator=(const Bag &) = delete;
    int getNumberOfTetrominos() const;
    static Bag & getInstance();
    Tetromino &getNext();
    const Tetromino& peekNext() const;
    int size();
    std::vector<Tetromino> getAvailableTetrominos() const;
};


#endif //TETRIS_DEV4_PROJET_BAG_H
