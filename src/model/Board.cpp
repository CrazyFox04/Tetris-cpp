//
// Created by Julien Delcombel on 07/03/2024.
//

#include "Board.h"
#include <random>
/**
class Board {
    int width;
    int height;
    std::vector<Tetromino> tetrominos;
    bool occupied[1][1];
    Position refPosition;
*/

    Board::Board() : Board(10, 20, 1) {
    }

    Board::Board(int w, int h, int difficulty)
        : width(w), height(h), occupied(h, std::vector<bool>(w, false)) {
        refPosition = Position(width / 2 - 1, 0);
        initialize(difficulty);
    }

    void Board::initialize(int difficulty) {
        if (difficulty < 1) difficulty = 1;
        if (difficulty > 20) difficulty = 20;

        double fillPercentage = (difficulty - 1) * (70.0 / 19.0);
        int linesToFill = static_cast<int>( (fillPercentage / 100) * height);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution d(fillPercentage / 100);

        for (auto &row : occupied) {
            std::fill(row.begin(), row.end(), false);
        }

        for (int i = height - linesToFill; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                occupied[i][j] = d(gen);
            }
        }
    }

    void Board::addTetromino(Tetromino tetromino) {
        auto cells = tetromino.get_relative_cells();

        std::vector<Position> absolutePositions;
        for (const auto & cell : cells) {
            int absX = refPosition.get_x() + cell.get_x();
            int absY = refPosition.get_y() + cell.get_y();

            if (isOccupied(absY, absX)) {
                // Game over ne devrions nous pas ajouter un atrribut pour cela?
                return;
            }
            absolutePositions.push_back(Position(absX, absY));
        }
        for (const auto & pos : absolutePositions) {
            occupied[pos.get_y()][pos.get_x()] = true;
        }
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

    void Board::rotateActiveTetromino(Rotation rotation) {
        Tetromino &activeTetromino = tetrominos.back();
         auto originalCells = activeTetromino.get_relative_cells();

         //Tenter la rotation
         if (rotation == Rotation::CLOCKWISE) {
            activeTetromino.rotateClockwise();
         } else {
            activeTetromino.rotateCounterClockwise();
         }
         // Vérifier si la rotation est valide
         for (const auto& cell : activeTetromino.get_relative_cells()) {
             int absX = cell.get_x();
             int absY = cell.get_y();
             if (isOutside(absX, absY) || isOccupied(absX, absY)) {
                 // Annuler la rotation si invalide
                 activeTetromino.set_relative_cells(originalCells);
                 return;
             }
         }
         // Mettre à jour occupied
         // Remettre les anciennes cellules à false
         for (const auto& cell : originalCells) {
           int absX = cell.get_x() + activeTetromino.get_ref_position().get_x();
           int absY = cell.get_y() + activeTetromino.get_ref_position().get_y();
           occupied[absY][absX] = false;
         }
         // Mettre les nouvelles à true
         for (const auto& cell : activeTetromino.get_relative_cells()) {
           int absX = cell.get_x() + activeTetromino.get_ref_position().get_x();
           int absY = cell.get_y() + activeTetromino.get_ref_position().get_y();
           occupied[absY][absX] = true;
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