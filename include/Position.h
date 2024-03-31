#ifndef TETRIS_DEV4_PROJET_POSITION_H
#define TETRIS_DEV4_PROJET_POSITION_H
#include "Direction.h"

/**
 * @class Position
 * @brief Represents a position in a 2D space with x and y coordinates.
 *
 * The Position class is used to define a two-dimensional point in space.
 * It includes various operator overloads to manipulate 2D positions easily.

 */
class Position {
    int x; //!< The x coordinate of the position.
    int y; //!< The y coordinate of the position.
public:

    /**
     * Constructor for Position.
     * @param x the x coordinate. Default is 0.
     * @param y  the y coordinate. Default is 0.
     */
    Position(int x = 0, int y = 0);

    /**
     * Getter for x.
     * @return the x coordinate.
     */
    int get_x() const { return x; }

    /**
     * Getter for y.
     * @return the y coordinate.
     */
    int get_y() const { return y; }


    void operator+=(const Direction2D& direction);
    void operator-=(const Direction2D& direction);
    void operator+=(const Position& position);
};
Position operator+(const Position &position, const Direction2D& direction);
Position operator+(const Direction2D& direction, const Position &position);
Position operator-(const Position &position, const Direction2D& direction);
Position operator-(const Direction2D& direction, const Position &position);
bool operator==(const Position &position, const Position &position2);
#endif //TETRIS_DEV4_PROJET_POSITION_H
