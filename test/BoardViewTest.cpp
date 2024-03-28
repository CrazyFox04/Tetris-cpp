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
    b.addTetromino(Tetromino(1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)})); // I
    b.addTetromino(Tetromino(2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)})); // O
    EXPECT_NO_THROW(bv.drawBoard(b));
}

TEST(BoardViewTest, drawBoardWithTetrominosOutOfBound) {
    BoardView bv;
    Board b;
    b.addTetromino(Tetromino(1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)})); // I
    b.addTetromino(Tetromino(2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)})); // O
    b.addTetromino(Tetromino(3, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(3, 0)})); // T
    b.addTetromino(Tetromino(4, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1)})); // S
    b.addTetromino(Tetromino(5, Position(0, 0), {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)})); // Z
    b.addTetromino(Tetromino(6, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(2, 1)})); // J
    b.addTetromino(Tetromino(7, Position(0, 0), {Position(0, 0), Position(1, 0), Position(2, 0), Position(0, 1)})); // L
    EXPECT_NO_THROW(bv.drawBoard(b));
}