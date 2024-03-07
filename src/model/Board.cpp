//
// Created by Julien Delcombel on 07/03/2024.
//

#include "Board.h"
/**
class Board {
    int width;
    int height;
    std::vector<Tetromino> tetrominos;
    bool occupied[1][1];
    Position refPosition;
*/

    Board::Board() {
        width = 10;
        height = 20;
        initialize();
    }

    Board::Board(int col, int row, int difficulty): width(col), height(row) {
        initialize(difficulty);
    }

    void Board::initialize(int difficulty) {
        occupied = new bool *[height];
        for (int i = 0; i < height; i++) {
            occupied[i] = new bool[width];
            for (int j = 0; j < width; j++) {
                occupied[i][j] = false;
            }
        }
    }
    void Board::addTetromino(Tetromino tetromino){
        tetrominos.push_back(tetromino);
    }

    void Board::moveActiveTetromino(Direction2D direction) {
        for (auto &cell: tetrominos.back().get_relative_cells()) {
            int newX = cell.get_x() + direction.first;
            int newY = cell.get_y() + direction.second;

            if (isOutside(newX, newY) || isOccupied(newX, newY)) {
                return;
            }
        }
        tetrominos.back().move(direction.first, direction.second);
    }

    void Board::rotateActiveTetromino(Direction direction) {
        if (direction == Direction::CLOCKWISE) {
            tetrominos.back().rotateClockwise();
        } else {
            tetrominos.back().rotateCounterClockwise();
        }
    }

    bool Board::isOutside(int row, int column) {
        return row < 0 || row >= height || column < 0 || column >= width;
    }

    bool Board::isOccupied(int row, int column) {
        return occupied[row][column];
    }

    int Board::removeCompleteLines() {
        int linesRemoved = 0;
        for (int i = 0; i < height; i++) {
            if (isLineComplete(i)) {
                clearLine(i);
                moveLinesDown(i);
                linesRemoved++;
            }
        }
        return linesRemoved;
    }

bool Board::isLineComplete(int line) {
    for (int j = 0; j < width; j++) {
        if (!occupied[line][j]) {
            return false;
        }
    }
    return true;
}

void Board::clearLine(int line) {
    for (int j = 0; j < width; j++) {
        occupied[line][j] = false;
    }
}

void Board::moveLinesDown(int line) {
    for (int i = line; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            occupied[i][j] = occupied[i + 1][j];
        }
    }
}

    bool Board::isGameOver() {
        for (int j = 0; j < width; j++) {
            if (occupied[0][j]) {
                return true;
            }
        }
        return false;
    }