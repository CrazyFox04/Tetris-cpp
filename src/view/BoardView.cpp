//
// Created by Julien Delcombel on 17/03/2024.
//

#include "BoardView.h"
#include "Board.h"

#include <iostream>
#include <map>

BoardView::BoardView() {
}

void BoardView::display() {


/*
//const auto & board = Board::getInstance(); todo : probably a bad idea
const auto & tetrominos = board.get_tetrominos();

std::map<int, char> tetrosSymbols = {
        {1, 'I'},
        {2, 'O'},
        {3, 'T'},
        {4, 'S'},
        {5, 'Z'},
        {6, 'J'},
        {7, 'L'}
};

std::vector<std::vector<char>> displayGrid(occupied.size(), std::vector<char>(occupied[0].size(), ' '));

for (int y = 0; y < occupied.size(); ++y) {
    for (int x = 0; x < occupied[y].size(); ++x) {
        if (occupied[y][x]) {
            std::cout << 'x';
        }
    }
}
for (const auto & tetro : tetrominos) {
    auto cells = tetro.get_relative_cells();
    char symbol = tetrosSymbols[tetro.get_id()];
    for (const auto & cell : cells) {
        int x = cell.get_x();
        int y = cell.get_y();
        if (x >= 0 && x < occupied[0].size() && y >= 0 && y < occupied.size()) {
            occupied[y][x] = symbol;
            }
        }
    }
    */
}

