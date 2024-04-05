#ifndef BAGVIEW_H
#define BAGVIEW_H

#include <map>
#include <vector>

#include "Tetromino.h"
#include "Bag.h"

/**
 * @class BagView
 * @brief Displays the next tetromino in the bag.
 *
 * This class is responsible for drawing the next tetromino in the bag.
 */
class BagView {
    /**
     * Create a mapping of tetromino IDs to symbols.
     * @return A map of tetromino IDs to symbols.
     */
    std::map<int, char> createSymbolMap() const;

    /**
     * Create a grid for the tetromino.
     * @param tetromino The tetromino to create a grid for.
     * @param tSymbol The symbol to use for the tetromino.
     * @return A grid representing the tetromino.
     */
    std::vector<std::vector<char>> createAndFillGrid(const Tetromino &tetromino, char tSymbol) const;

    /**
     * Print the grid to the console.
     * @param grid The grid to print.
     */
    void printGrid(const std::vector<std::vector<char>> &grid) const;

public:
    /**
     * Draw the next tetromino in the bag.
     * @param bag The bag to draw the next tetromino from.
     */
    void drawNextTetromino(const Bag &bag) const;
};

#endif //BAGVIEW_H
