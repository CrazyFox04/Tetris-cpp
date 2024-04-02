#include "BagView.h"

 void BagView::drawNextTetromino(const Bag& bag) const {
    const Tetromino& nextTetromino = bag.peekNext();

    //Mapping tetrominos id to symbols
    std::map<int, char> symbols = {
            {1, 'i'}, {2, 'o'}, {3, 't'}, {4, 's'}, {5, 'z'}, {6, 'j'}, {7, 'l'}
    };

    char tSymbol = symbols.at(nextTetromino.get_id());
    int gridSize = std::max(nextTetromino.get_length(), nextTetromino.get_height());
    std::vector<std::vector<char>> grid(gridSize, std::vector<char>(gridSize, ' '));
    int centerX = gridSize / 2;
    int centerY = gridSize / 2;

    for (const auto& cell : nextTetromino.get_relative_cells()) {
        int x = centerX + cell.get_x();
        int y = centerY + cell.get_y();
        if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
            grid[y][x] = tSymbol;
        }
    }

    //Print the grid
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}