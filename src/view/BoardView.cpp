//
// Created by Julien Delcombel on 17/03/2024.
//

#include "BoardView.h"

void BoardView::drawBoard(const Board &board) const {
    // TODO: remplacer board.xxx par facade.xxx
    auto width = board.getWidth();
    auto height = board.getHeight();
    const auto& tetrominos = board.getTetrominos();


    // Mapping tetros id to symbols
    std::map<int, char> symbols = {
            {1, 'i'}, {2, 'o'}, {3, 't'}, {4, 's'}, {5, 'z'}, {6, 'j'}, {7, 'l'}
    };

    // Create char[][] and initialize it with empty spaces
    std::vector<std::vector<char>> boardGame(height, std::vector<char>(width, ' '));

    // Check the position of each tetrominos and fill the boardGame
    for (const auto& t : tetrominos) {
        char tSymbol = symbols.at(t.get_id());
        for (const auto& cell : t.get_relative_cells()) {
            int absX = board.getRefPosition().get_x() + cell.get_x();
            int absY = board.getRefPosition().get_y() + cell.get_y();
            if (absX >= 0 && absX < width && absY >= 0 && absY < height) {
                boardGame[absY][absX] = tSymbol;
            }
        }
    }

    //
    for (const auto& row : boardGame) {
        std::cout << '#'; //Left border
        for (char c : row) {
            std::cout << c;
        }
        std::cout << '#' << std::endl; //Right border
    }
    std::cout << std::string(width + 2, '#') << std::endl; //Bottom border
}

