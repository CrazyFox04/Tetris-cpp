//
// Created by Julien Delcombel on 17/03/2024.
//

#include "BoardView.h"
#include "Board.h"

#include <iostream>
#include <map>

void BoardView::drawBoard(const Board &board) {
    const auto& tetrominos = board.getTetrominos();
    int width = board.getWidth();
    int height = board.getHeight();

    //Mapping tetros id to symbols
    std::map<int, char> tetrosSymbols = {
            {1, 'i'}, {2, 'o'}, {3, 't'}, {4, 's'}, {5, 'z'}, {6, 'j'}, {7, 'l'}
    };

    //Creating the grid
    std::vector<std::vector<char>> displayGrid(height, std::vector<char>(width, ' '));

    //Fill the grid with the symbol
    for (const auto& tetro : tetrominos) {
        char symbol = tetrosSymbols[tetro.get_id()];
        for (const auto& cell : tetro.get_relative_cells()) {
            int x = cell.get_x() + board.getRefPosition().get_x();
            int y = cell.get_y() + board.getRefPosition().get_y();
            if (x >= 0 && x < width && y >= 0 && y < height) {
                displayGrid[y][x] = symbol;
            }
        }
    }

    //Print the board in a canvas
    for (const auto& row : displayGrid) {
        std::cout << '#'; //Left border
        for (char c : row) {
            std::cout << c;
        }
        std::cout << '#' << std::endl; //Right border
    }
    std::cout << std::string(width + 2, '#') << std::endl; //Bottom border
}

