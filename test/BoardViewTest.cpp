//
// Created by Julien Delcombel on 23/03/2024.
//

#include <gtest/gtest.h>
#include "BoardView.h"

TEST(BoardViewTest, drawBoard) {
    BoardView bv;
    Board b;
    EXPECT_NO_THROW(bv.drawBoard(b));
}

TEST(BoardViewTest, drawBoardWithTetrominos) {
    BoardView bv;
    Board b;
    b.addTetromino({1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)}, true}); // I
    b.addTetromino({2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)}, true}); // O
    EXPECT_NO_THROW(bv.drawBoard(b));
}

TEST(BoardViewTest, drawBoardWithTetrominosOutOfBound) {
    BoardView bv;
    Board b;
    b.addTetromino({1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)}, true}); // I
    b.addTetromino({2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)}, true}); // O
    b.addTetromino({3, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)}, true}); // T
    b.addTetromino({4, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1)}, true}); // S
    b.addTetromino({5, Position(0, 0), {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)}, true}); // Z
    b.addTetromino({6, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1)}, true}); // J
    b.addTetromino({7, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(0, 1)}, true}); // L
    EXPECT_NO_THROW(bv.drawBoard(b));
}