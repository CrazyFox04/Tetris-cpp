//
// Created by Julien Delcombel on 17/03/2024.
//

#include "BagView.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void BagView::drawNextTetromino(const Tetromino & nextTetromino) {
    auto cells = nextTetromino.get_relative_cells();

    //Mapping tetros id to symbols
    std::map<int, char> tetrosSymbols = {
            {1, 'i'}, {2, 'o'}, {3, 't'}, {4, 's'}, {5, 'z'}, {6, 'j'}, {7, 'l'}
    };
    //Getting the symbol of the tetromino
    char symbol = tetrosSymbols[nextTetromino.get_id()];

    //Finding the min and max x and y values to draw the tetromino
    int minX = std::min_element(cells.begin(), cells.end(), [](const Position& a, const Position& b) {
        return a.get_x() < b.get_x();
    })->get_x();
    int maxX = std::max_element(cells.begin(), cells.end(), [](const Position& a, const Position& b) {
        return a.get_x() < b.get_x();
    })->get_x();
    int minY = std::min_element(cells.begin(), cells.end(), [](const Position& a, const Position& b) {
        return a.get_y() < b.get_y();
    })->get_y();
    int maxY = std::max_element(cells.begin(), cells.end(), [](const Position& a, const Position& b) {
        return a.get_y() < b.get_y();
    })->get_y();

    //Creating the grid
    std::vector<std::vector<char>> grid(maxY - minY + 1, std::vector<char>(maxX - minX + 1, ' '));

    //Fill the grid with the symbol
    for (const auto& cell : cells) {
        int x = cell.get_x() - minX;
        int y = cell.get_y() - minY;
        grid[y][x] = symbol;
    }

    //Print the grid
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}