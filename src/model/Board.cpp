//
// Created by Julien Delcombel on 07/03/2024.
//

#include "Board.h"
#include <random>
#include <algorithm>

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
    int linesToFill = static_cast<int>((fillPercentage / 100) * height);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(fillPercentage / 100);

    for (auto&row: occupied) {
        std::fill(row.begin(), row.end(), false);
    }
    for (int i = height - linesToFill; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            occupied[i][j] = d(gen);
        }
    }
}

void Board::addTetromino(const Tetromino&tetromino) {
    auto cells = tetromino.get_relative_cells();

    std::vector<Position> absolutePositions;
    for (const auto&cell: cells) {
        int absX = refPosition.get_x() + cell.get_x();
        int absY = refPosition.get_y() + cell.get_y();

        if (isOccupied(absY, absX)) {
            // Game over ne devrions nous pas ajouter un atrribut pour cela?
            return;
        }
        absolutePositions.emplace_back(absX, absY);
    }
    for (const auto&pos: absolutePositions) {
        occupied[pos.get_y()][pos.get_x()] = true;
    }
    tetrominos.push_back(tetromino);
}

void Board::moveActiveTetromino(Direction2D direction) {
    auto&activeTetromino = tetrominos.back();
    auto cells = activeTetromino.get_relative_cells();
    clearOccupiedForActiveTetromino();
    for (const auto&cell: cells) {
        Position newPos = cell + direction;
        if (isOutside(newPos.get_x(), newPos.get_y()) || isOccupied(newPos.get_x(), newPos.get_y())) {
            return;
        }
    }
    activeTetromino.move(direction.first, direction.second);
    for (const auto&cell: activeTetromino.get_relative_cells()) {
        int absX = refPosition.get_x() + cell.get_x();
        int absY = refPosition.get_y() + cell.get_y();
        occupied[absY][absX] = true;
    }
}

void Board::rotateActiveTetromino(Rotation rotation) {
    Tetromino&activeTetromino = tetrominos.back();
    auto originalCells = activeTetromino.get_relative_cells();
    clearOccupiedForActiveTetromino();
    //Tenter la rotation
    if (rotation == Rotation::CLOCKWISE) {
        activeTetromino.rotateClockwise();
    }
    else {
        activeTetromino.rotateCounterClockwise();
    }
    // Vérifier si la rotation est valide
    for (const auto&cell: activeTetromino.get_relative_cells()) {
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
    for (const auto&cell: originalCells) {
        int absX = cell.get_x() + activeTetromino.get_ref_position().get_x();
        int absY = cell.get_y() + activeTetromino.get_ref_position().get_y();
        occupied[absY][absX] = false;
    }
    // Mettre les nouvelles à true
    for (const auto&cell: activeTetromino.get_relative_cells()) {
        int absX = cell.get_x() + refPosition.get_x();
        int absY = cell.get_y() + refPosition.get_y();
        occupied[absY][absX] = true;
    }
}

bool Board::isOutside(int row, int column) const {
    return row < 0 || row >= height || column < 0 || column >= width;
}

bool Board::isOccupied(int row, int column) const {
    return occupied[column][row];
}

int Board::removeCompleteLines() {
    int linesRemoved = 0;
    for (int y = 0; y < height; ++y) {
        if (isLineComplete(y)) {
            clearLine(y);
            moveLinesDown(y);
            linesRemoved++;
        }
    }
    return linesRemoved;
}

bool Board::isLineComplete(int line) const {
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

    for (auto&tetro: tetrominos) {
        std::vector<Position> cells = tetro.get_relative_cells();
        cells.erase(std::remove_if(cells.begin(), cells.end(), [line](const Position&pos) {
                        return pos.get_y() == line;
                    }),
                    cells.end()
        );
        tetro.set_relative_cells(cells);
    }
}

void Board::moveLinesDown(int clearedline) {
    for (int y = clearedline; y > 0; --y) {
        for (int x = 0; x < width; ++x) {
            occupied[y][x] = occupied[y - 1][x];
        }
    }
    Direction2D down(0, 1);
    for (auto&tetromino: tetrominos) {
        for (auto&cell: tetromino.get_relative_cells()) {
            if (cell.get_y() < clearedline) {
                cell += down;
            }
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

Tetromino& Board::getActiveTetromino() {
    return tetrominos.back();
}

const std::vector<Tetromino> Board::getTetrominos() const {
    std::vector<Tetromino> constTetrominos;
    for (const auto&tetromino: tetrominos) {
        constTetrominos.push_back(tetromino);
    }
    return constTetrominos;
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

const std::vector<std::vector<bool>> Board::getOccupied() const {
    std::vector<std::vector<bool>> constOccupied;
    for (const auto&row: occupied) {
        constOccupied.push_back(row);
    }
    return constOccupied;
}

Position Board::getRefPosition() const {
    return refPosition;
}

void Board::clearOccupiedForActiveTetromino() {
    auto&activeTetromino = tetrominos.back();
    auto cells = activeTetromino.get_relative_cells();
    for (const auto&cell: cells) {
        int absX = refPosition.get_x() + cell.get_x();
        int absY = refPosition.get_y() + cell.get_y();
        occupied[absY][absX] = false;
    }
}