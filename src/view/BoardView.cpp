#include "BoardView.h"

void BoardView::drawBoard(const Board &board) {
    auto width = board.getWidth();
    auto height = board.getHeight();
    auto tetrominos = board.getTetrominos();
    auto boardRefPos = board.getRefPosition();

    auto boardGame = initializeBoard(width, height);
    fillBoardWithTetrominos(tetrominos, boardGame, width, height, boardRefPos);
    displayBoard(boardGame);
}

std::vector<std::vector<char>> BoardView::initializeBoard(int width, int height) {
    return std::vector<std::vector<char>>(height, std::vector<char>(width, '.'));
}

void
BoardView::fillBoardWithTetrominos(const std::vector<Tetromino>& tetrominos, std::vector<std::vector<char>>& boardGame,
                                   int boardWidth, int boardHeight, Position boardRefPos) {
    std::map<int, char> symbols = {
            {1, 'i'}, {2, 'o'}, {3, 't'}, {4, 's'}, {5, 'z'}, {6, 'j'}, {7, 'l'}
    };
    for (const auto& t: tetrominos) {
        char tSymbol = symbols.at(t.get_id());
        for (const auto& cell: t.get_relative_cells()) {
            int absX = boardRefPos.get_x() + cell.get_x();
            int absY = boardRefPos.get_y() + cell.get_y();
            if (absX >= 0 && absX < boardWidth && absY >= 0 && absY < boardHeight) {
                boardGame[absY][absX] = tSymbol;
            }
        }
    }
}

void BoardView::displayBoard(const std::vector<std::vector<char>> &boardGame) {
    for (const auto &row: boardGame) {
        std::cout << '#'; // Left border
        for (char c: row) {
            std::cout << c;
        }
        std::cout << '#' << std::endl; // Right border
    }
    std::cout << std::string(boardGame[0].size() + 2, '#') << std::endl; // Bottom border
}

