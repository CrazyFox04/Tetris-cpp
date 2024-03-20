//
// Created by Enzo Renard on 06/03/2024.
//
#include "Tetromino.h"

Tetromino::Tetromino(int id, Position center, std::vector<Position> cells) : id(id), refPosition(center),
                                                                             cells(std::move(cells)) {
}

void Tetromino::rotateClockwise() {
    for (auto&cell: cells) {
        int x = cell.get_x();
        int y = cell.get_y();
        cell = Position(-y, x);
    }
}

void Tetromino::rotateCounterClockwise() {
    for (auto&cell: cells) {
        int x = cell.get_x();
        int y = cell.get_y();
        cell = Position(y, -x);
    }
}

void Tetromino::move(int dx, int dy) {
    refPosition += Direction2D(dx, dy);
}

int Tetromino::get_id() const {
    return id;
}

std::vector<Position> Tetromino::get_relative_cells() const {
    std::vector<Position> relativeCells;
    relativeCells.reserve(cells.size());
    for (auto&cell: cells) {
        relativeCells.emplace_back(cell.get_x() + refPosition.get_x(),
                                   cell.get_y() + refPosition.get_y());
    }
    return relativeCells;
}

Position Tetromino::get_ref_position() const {
    return {refPosition.get_x(), refPosition.get_y()};
}

void Tetromino::set_relative_cells(const std::vector<Position>& newCells) {
    cells = newCells;
}

bool operator==(const Tetromino &Tetromino1, const Tetromino &Tetromino2) {
    return Tetromino1.get_id() == Tetromino2.get_id() && Tetromino1.get_ref_position() == Tetromino2.get_ref_position() &&
           Tetromino1.get_relative_cells() == Tetromino2.get_relative_cells();
}