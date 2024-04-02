//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef DIRECTION_H
#define DIRECTION_H
#include <utility>

/**
 * @brief Alias for a 2D direction representation.
 *
 * Direction2D is defined as a pair of integers, representing 2D movement
 * with the first element as the x-component and the second as the y-component.
 */
using Direction2D = std::pair<int, int>;

/**
 * @struct Direction
 * @brief Struct for defining common directions in a 2D space.
 *
 * The struct provides static constant directions as 2D vectors. These are commonly used
 * directions in a 2D grid, such as in games or graphical applications.
 */
struct Direction {
    static const Direction2D RIGHT; ///< Direction vector representing movement to the right.
    static const Direction2D DOWN;  ///< Direction vector representing downward movement.
    static const Direction2D LEFT;  ///< Direction vector representing movement to the left.
};

/**
 * @enum Rotation
 * @brief Enumeration for rotation directions.
 *
 * Defines possible rotation directions for objects that can be rotated,
 * typically used in graphical applications or games.
 */
enum class Rotation {
    CLOCKWISE,         ///< Represents a rotation in the clockwise direction.
    COUNTERCLOCKWISE  ///< Represents a rotation in the counter-clockwise direction.
};


#endif //DIRECTION_H
