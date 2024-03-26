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
    Board b(10, 10, 1);
    ASSERT_EQ(b.getWidth(), 10);
    ASSERT_EQ(b.getHeight(), 10);
    ASSERT_EQ(b.getOccupied().size(), 10);
    ASSERT_EQ(b.getOccupied().at(0).size(), 10);
}

TEST(Board, constructor_with_parameters_too_small) {
    ASSERT_THROW(Board b(1, 1, 1), std::invalid_argument);
}

TEST(Board, constructor_with_parameters_edge) {
    int maxHeight = 0;
    int maxWidth = 0;
    for (const auto&available_tetromino: Bag::getInstance().getAvailableTetrominos()) {
        if (available_tetromino.get_height() > maxHeight) {
            maxHeight = available_tetromino.get_height();
        }
        if (available_tetromino.get_length() > maxWidth) {
            maxWidth = available_tetromino.get_length();
        }
    }
    // Make the board 2times greater than max size of tetro
    Board b(maxWidth * 2 + 1, maxHeight * 2 + 1, 1);
    ASSERT_EQ(b.getWidth(), maxWidth*2+1);
    ASSERT_EQ(b.getHeight(), maxHeight*2+1);
    ASSERT_THROW(Board b3(maxWidth - 1, maxHeight, 1), std::invalid_argument);
    ASSERT_THROW(Board b4(maxWidth, maxHeight - 1, 1), std::invalid_argument);
    ASSERT_THROW(Board b4(maxWidth - 1, maxHeight - 1, 1), std::invalid_argument);
}

TEST(Board, add_tetromino) {
    Board b(10, 10, 1);
    Tetromino t = Bag::getInstance().getAvailableTetrominos().at(0);
    b.addTetromino(t);
    ASSERT_EQ(b.getTetrominos().size(), 1);
}

TEST(Board, move_active_tetromino) {
    Board b(10, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino(Direction2D(0, 1)); // Down
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
}

TEST(Board, move_active_tetromino_4dirs_happy_path) {
    Board b(10, 10, 1);
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
    Board b(10, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino(Direction2D(0, -1)); // Up
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 0);
}

TEST(Board, move_active_tetromino_collision) {
    Board b(10, 10, 1);
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
    b.moveActiveTetromino({0, 4});
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
    Board b(10, 10, 1);
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
    Board b(10, 10, 1);
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

TEST(Board, remove_complete_lines) {
    Board b(10, 10, 1);
    Tetromino t{2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)}};
    b.addTetromino(t);
    b.moveActiveTetromino({-4, 8});
    b.addTetromino(t);
    b.moveActiveTetromino({-2, 8});
    b.addTetromino(t);
    b.moveActiveTetromino({0, 8});
    b.addTetromino(t);
    b.moveActiveTetromino({2, 8});
    b.addTetromino(t);
    b.moveActiveTetromino({4, 8});
    b.addTetromino(t);
    b.moveActiveTetromino({6, 8});
    b.addTetromino(t);
    b.moveActiveTetromino({8, 8});
    ASSERT_EQ(b.removeCompleteLines(), 2);
    for (const auto&bit_references: b.getOccupied()) {
        for (const auto&bit_reference: bit_references) {
            ASSERT_EQ(bit_reference, false);
        }
    }
}

TEST(Board, game_over) {
    Board b(10, 10, 1);
    ASSERT_FALSE(b.isGameOver());
    b.addTetromino(Bag::getInstance().getAvailableTetrominos().at(0));
    ASSERT_FALSE(b.isGameOver());
    b.addTetromino(Bag::getInstance().getAvailableTetrominos().at(0));
    ASSERT_TRUE(b.isGameOver());
}
