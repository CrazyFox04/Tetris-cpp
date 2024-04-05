#include "Tetromino.h"
#include <stdexcept>

Tetromino::Tetromino(const int id, const Position center, std::vector<Position> cells, bool rotable_) :
id(id), refPosition(center), cells(std::move(cells)), rotable(rotable_) {
}

Tetromino& Tetromino::rotate(Rotation rotation) {
    if (!rotable) {
        throw std::runtime_error("Tetromino is not rotatable");
    }
    for (auto &cell: cells) {
        if (!(cell == Position(0, 0))) {
            int x = cell.get_x();
            int y = cell.get_y();
            if (rotation == Rotation::CLOCKWISE) {
                cell = Position(-y, x);
            } else {
                cell = Position(y, -x);
            }
        }
    }
    return *this;
}

Tetromino& Tetromino::move(int dx, int dy) {
    refPosition += Direction2D(dx, dy);
    return *this;
}

int Tetromino::get_id() const {
    return id;
}

std::vector<Position> Tetromino::get_relative_cells() const {
    std::vector<Position> relativeCells;
    relativeCells.reserve(cells.size());
    for (auto &cell: cells) {
        relativeCells.emplace_back(cell.get_x() + refPosition.get_x(),
                                   cell.get_y() + refPosition.get_y());
    }
    return relativeCells;
}

Position Tetromino::get_ref_position() const {
    return {refPosition.get_x(), refPosition.get_y()};
}

void Tetromino::set_relative_cells(const std::vector<Position> &newCells) {
    cells.clear();
    for (const auto &item: newCells) {
        cells.emplace_back(item.get_x() - refPosition.get_x(), item.get_y() - refPosition.get_y());
    }
}

bool operator==(const Tetromino &Tetromino1, const Tetromino &Tetromino2) {
    return Tetromino1.get_id() == Tetromino2.get_id() &&
           Tetromino1.get_ref_position() == Tetromino2.get_ref_position() &&
           Tetromino1.get_relative_cells() == Tetromino2.get_relative_cells();
}

int Tetromino::get_length() const {
    int min = 0;
    int max = 0;
    for (const auto &cell: cells) {
        if (cell.get_x() < min) {
            min = cell.get_x();
        }
        if (cell.get_x() > max) {
            max = cell.get_x();
        }
    }
    return max - min + 1;
}

int Tetromino::get_height() const {
    int min = 0;
    int max = 0;
    for (const auto &cell: cells) {
        if (cell.get_y() < min) {
            min = cell.get_y();
        }
        if (cell.get_y() > max) {
            max = cell.get_y();
        }
    }
    return max - min + 1;
}

bool Tetromino::isRotable() const {
    return rotable;
}