//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef BAGVIEW_H
#define BAGVIEW_H

#include "Bag.h"
#include <iostream>
#include <map>
#include <algorithm>

/**
 * @class BagView
 * @brief Displays the next tetromino in the bag.
 *
 * This class is responsible for drawing the next tetromino in the bag.
 */
class BagView {
public:
    /**
     * Draw the next tetromino in the bag.
     * @param bag The bag to draw the next tetromino from.
     */
     void drawNextTetromino(const Bag& bag) const;
};
#endif //BAGVIEW_H
