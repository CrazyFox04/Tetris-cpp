//
// Created by Enzo Renard on 05/03/2024.
//
#include <gtest/gtest.h>
#include "Position.h"
TEST(Position, constructor) {
    Position p(1, 2);
    ASSERT_EQ(p.get_x(), 1);
    ASSERT_EQ(p.get_y(), 2);
}
TEST(Position, addition) {
    Position p(1, 2);
    Direction2D d(3, 4);
    Position p2 = p + d;
    ASSERT_EQ(p2.get_x(), 4);
    ASSERT_EQ(p2.get_y(), 6);
}
TEST(Position, subtraction) {
    Position p(1, 2);
    Direction2D d(3, 4);
    Position p2 = p - d;
    ASSERT_EQ(p2.get_x(), -2);
    ASSERT_EQ(p2.get_y(), -2);
}
TEST(Position, addition_assignment) {
    Position p(1, 2);
    Direction2D d(3, 4);
    p += d;
    ASSERT_EQ(p.get_x(), 4);
    ASSERT_EQ(p.get_y(), 6);
}
TEST(Position, subtraction_assignment) {
    Position p(1, 2);
    Direction2D d(3, 4);
    p -= d;
    ASSERT_EQ(p.get_x(), -2);
    ASSERT_EQ(p.get_y(), -2);
}
TEST(Position, addition_unmodified) {
    Position p(1, 2);
    Direction2D d(3, 4);
    p + d;
    ASSERT_EQ(p.get_x(), 1);
    ASSERT_EQ(p.get_y(), 2);
}
TEST(Position, subtraction_unmodified) {
    Position p(1, 2);
    Direction2D d(3, 4);
    p - d;
    ASSERT_EQ(p.get_x(), 1);
    ASSERT_EQ(p.get_y(), 2);
}
TEST(Position, copy_constructor_makes_deep_copy) {
    Position p(1, 2);
    Position p2 = p;
    p2 += Direction2D(3, 4);
    ASSERT_EQ(p.get_x(), 1);
    ASSERT_EQ(p.get_y(), 2);
}