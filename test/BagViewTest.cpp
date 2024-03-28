//
// Created by Julien Delcombel on 23/03/2024.
//

#include <gtest/gtest.h>
#include "BagView.h"

TEST(BagViewTest, drawNextTetromino) {
    BagView bv;
    Tetromino t1 { 1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)} }; // I
    EXPECT_NO_THROW(bv.drawNextTetromino(t1));
    Tetromino t2 { 2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)} }; // O
    EXPECT_NO_THROW(bv.drawNextTetromino(t2));
}

