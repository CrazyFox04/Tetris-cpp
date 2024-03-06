#ifndef TETRIS_DEV4_PROJET_POSITION_H
#define TETRIS_DEV4_PROJET_POSITION_H
#include "Direction.h"

class Position {
    int x;
    int y;
public:
    Position(int x = 0, int y = 0);
    int get_x() const { return x; }
    int get_y() const { return y; }
    void operator+=(const Direction2D& direction);
    void operator-=(const Direction2D& direction);
};
Position operator+(const Position &position, const Direction2D& direction);
Position operator+(const Direction2D& direction, const Position &position);
Position operator-(const Position &position, const Direction2D& direction);
Position operator-(const Direction2D& direction, const Position &position);
#endif //TETRIS_DEV4_PROJET_POSITION_H
