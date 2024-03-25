//
// Created by Enzo Renard on 20/03/2024.
//
#include <gtest/gtest.h>
#include "Board.h"
#include "Tetromino.h"
#include "Bag.h"
#include "Direction.h"

TEST(Board, constructor) {
    Board b;
    ASSERT_EQ(b.getWidth(), 10);
    ASSERT_EQ(b.getHeight(), 20);
    ASSERT_EQ(b.getOccupied().size(), 20);
    ASSERT_EQ(b.getOccupied().at(0).size(), 10);
}

TEST(Board, constructor_with_parameters) {
    Board b(5, 10, 1);
    ASSERT_EQ(b.getWidth(), 5);
    ASSERT_EQ(b.getHeight(), 10);
    ASSERT_EQ(b.getOccupied().size(), 10);
    ASSERT_EQ(b.getOccupied().at(0).size(), 5);
}

TEST(Board, add_tetromino) {
    Board b(10, 10, 1);
    Tetromino t = Bag::getInstance().getAvailableTetrominos().at(0);
    b.addTetromino(t);
    ASSERT_EQ(b.getTetrominos().size(), 1);
}

TEST(Board, move_active_tetromino) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino(Direction2D(0, 1)); // Down
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
}

TEST(Board, move_active_tetromino_4dirs_happy_path) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino(Direction2D(0, 1)); // Down
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
    b.moveActiveTetromino(Direction2D(1, 0)); // Right
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
    b.moveActiveTetromino(Direction2D(0, -1)); // Up
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 0);
    b.moveActiveTetromino(Direction2D(-1, 0)); // Left
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 0);
}

TEST(Board, move_active_tetromino_out_of_bounds) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino(Direction2D(0, -1)); // Up
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 0);
}

TEST(Board, move_active_tetromino_collision) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino({0, 3});
    b.addTetromino(t);
    b.moveActiveTetromino({0, 1});
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
    b.moveActiveTetromino({0, 1});
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 2);
    b.moveActiveTetromino({0, 1});
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 2);
}

TEST(Board, rotate_active_tetromino) {
    Board b(10, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino({0,4});
    b.rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_y(), 4);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_y(), 3);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_y(), 2);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_y(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 4);
}

TEST(Board, rotate_active_tetromino_out_of_bounds) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.rotateActiveTetromino(Rotation::CLOCKWISE);
    // No rotation should have been done
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_y(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_y(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_y(), 2);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_y(), 3);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 0);
}

TEST(Board, rotate_active_tetromino_collision) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.rotateActiveTetromino(Rotation::CLOCKWISE);
    b.moveActiveTetromino({0, 1});
    b.addTetromino(t);
    b.rotateActiveTetromino(Rotation::CLOCKWISE);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_y(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_y(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_y(), 2);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_y(), 3);
}