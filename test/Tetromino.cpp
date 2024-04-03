//
// Created by Enzo Renard on 06/03/2024.
//
#include <gtest/gtest.h>
#include "Tetromino.h"

TEST(Tetromino, constructor) {
    Position center(1, 2);
    std::vector<Position> cells = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Tetromino t(1, center, cells, true);
    ASSERT_EQ(t.get_id(), 1);
    std::vector<Position> expected = {Position(1, 2), Position(1, 3), Position(2, 2), Position(2, 3)};
    ASSERT_EQ(t.get_relative_cells(), expected);
}

TEST(Tetromino, rotateClockwise) {
    Position center(1, 2);
    std::vector<Position> cells = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Tetromino t(1, center, cells, true);
    t.rotateClockwise();
    std::vector<Position> rotatedCells = {Position(0, 0), Position(-1, 0), Position(0, 1), Position(-1, 1)};
    std::vector<Position> expected = {Position(1, 2), Position(0, 2), Position(1, 3), Position(0, 3)};
    ASSERT_EQ(t.get_relative_cells(), expected);
}

TEST(Tetromino, rotateCounterClockwise) {
    Position center(1, 2);
    std::vector<Position> cells = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Tetromino t(1, center, cells, true);
    t.rotateCounterClockwise();
    std::vector<Position> rotatedCells = {Position(0, 0), Position(1, 0), Position(0, -1), Position(1, -1)};
    std::vector<Position> expected = {Position(1, 2), Position(2, 2), Position(1, 1), Position(2, 1)};
    ASSERT_EQ(t.get_relative_cells(), expected);
}

TEST(Tetromino, move) {
    Position center(1, 2);
    std::vector<Position> cells = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Tetromino t(1, center, cells, true);
    t.move(3, 4);
    std::vector<Position> movedCells = {Position(3, 4), Position(3, 5), Position(4, 4), Position(4, 5)};
    std::vector<Position> expected = {Position(4, 6), Position(4, 7), Position(5, 6), Position(5, 7)};
    ASSERT_EQ(t.get_relative_cells(), expected);
}

TEST(Tetromino, get_relative_cells) {
    Position center(1, 2);
    std::vector<Position> cells = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
    Tetromino t(1, center, cells, true);
    std::vector<Position> expected = {Position(1, 2), Position(1, 3), Position(2, 2), Position(2, 3)};
    ASSERT_EQ(t.get_relative_cells(), expected);
}
