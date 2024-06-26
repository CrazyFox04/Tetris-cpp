//
// Created by Enzo Renard on 20/03/2024.
//
#include <gtest/gtest.h>
#include "Bag.h"

TEST(Bag, getInstance) {
    Bag&bag = Bag::getInstance();
    Bag&bag2 = Bag::getInstance();
    ASSERT_EQ(&bag, &bag2);
}

TEST(Bag, getNext) {
    Bag&bag = Bag::getInstance();
    ASSERT_EQ(bag.size(), Bag::getInstance().getNumberOfTetrominos());
    bag.getNext();
    ASSERT_EQ(bag.size(), Bag::getInstance().getNumberOfTetrominos()-1);
    bag.getNext();
    ASSERT_EQ(bag.size(), Bag::getInstance().getNumberOfTetrominos()-2);
    for (int i = 0; i < bag.getNumberOfTetrominos() - 2; i++) {
        bag.getNext();
    }
}

TEST(Bag, shuffle) {
    Bag&bag = Bag::getInstance();
    for (int i = 0; i < bag.getNumberOfTetrominos(); i++) {
        bag.getNext();
    }
    ASSERT_EQ(bag.size(), 7);
    bag.getNext();
    ASSERT_EQ(bag.size(), Bag::getInstance().getNumberOfTetrominos()-1);
}
