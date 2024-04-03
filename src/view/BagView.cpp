#include "BagView.h"

void BagView::drawNextTetromino(const Bag &bag) const {
    const Tetromino& nextTetromino = bag.peekNext();
    auto tSymbol = createSymbolMap().at(nextTetromino.get_id());
    auto grid = createAndFillGrid(nextTetromino, tSymbol);
    printGrid(grid);
}

std::map<int, char> BagView::createSymbolMap() const {
    return {
            {1, 'i'}, {2, 'o'}, {3, 't'}, {4, 's'}, {5, 'z'}, {6, 'j'}, {7, 'l'}
    };
}

std::vector<std::vector<char>> BagView::createAndFillGrid(const Tetromino &tetromino, char tSymbol) const {
    int gridSize = std::max(tetromino.get_length(), tetromino.get_height());
    if (gridSize % 2 == 0) gridSize++;
    std::vector<std::vector<char>> grid(gridSize, std::vector<char>(gridSize, ' '));
    int centerX = gridSize / 2;
    int centerY = gridSize / 2;

    for (const auto& cell: tetromino.get_relative_cells()) {
        int x = centerX + cell.get_x();
        int y = centerY + cell.get_y();
        if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
            grid[y][x] = tSymbol;
        }
    }
    return grid;
}

void BagView::printGrid(const std::vector<std::vector<char>> &grid) const {
    for (const auto &row: grid) {
        for (char c: row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}