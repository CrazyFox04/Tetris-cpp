//
// Created by Julien Delcombel on 23/03/2024.
//

#include <gtest/gtest.h>
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "RotateClockwiseCommand.h"
#include "RotateCounterClockwiseCommand.h"
#include "Tetromino.h"
#include "Board.h"

TEST(Board, move_active_tetromino_4dirs_happy_path) {
    Board b(5, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    MoveDownCommand mdc;
    MoveLeftCommand mlc;
    MoveRightCommand mrc;
    mdc.execute();// Down
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
    mrc.execute(); // Right
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 1);
    mlc.execute(); // Left
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 0);
}

TEST(Board, rotate_tetromino_both_rotation) {
    RotateClockwiseCommand rcwc;
    RotateConterClockwiseCommand rccwc;
    Board b(10, 10, 1);
    Tetromino t{1, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}};
    b.addTetromino(t);
    b.moveActiveTetromino({0, 4});
    rccwc.execute();
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
    rcwc.execute();
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(0).get_y(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(1).get_y(), 1);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(2).get_y(), 2);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_relative_cells().at(3).get_y(), 3);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_x(), 0);
    ASSERT_EQ(b.getActiveTetromino().get_ref_position().get_y(), 4);
}