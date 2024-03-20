//
// Created by Julien Delcombel on 17/03/2024.
//

#include "BagView.h"
#include "Bag.h"

#include <iostream>

void BagView::display() {
    //Tetromino nextTetromino = Bag::getInstance().getNext();
    Tetromino nextTetromino = Tetromino(1, {}, {});
    auto cells = nextTetromino.get_relative_cells();

    int minX = std::min_element(cells.begin(), cells.end(),
                                [](const Position &a, const Position &b) {
                                    return a.get_x() < b.get_x();
                                })->get_x();
    int maxX = std::max_element(cells.begin(), cells.end(),
                                [](const Position &a, const Position &b) {
                                    return a.get_x() < b.get_x();
                                })->get_x();
    int minY = std::min_element(cells.begin(), cells.end(),
                                [](const Position &a, const Position &b) {
                                    return a.get_y() < b.get_y();
                                })->get_y();
    int maxY = std::max_element(cells.begin(), cells.end(),
                                [](const Position &a, const Position &b) {
                                    return a.get_y() < b.get_y();
                                })->get_y();

    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            if (std::find_if(cells.begin(), cells.end(), [x, y](const Position &pos) {
                return pos.get_x() == x && pos.get_y() == y;
            }) != cells.end()) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
    }
}