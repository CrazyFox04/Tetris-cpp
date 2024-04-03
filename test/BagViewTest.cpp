//
// Created by Julien Delcombel on 23/03/2024.
//

#include <gtest/gtest.h>
#include "BagView.h"

TEST(BagViewTest, drawNextTetromino) {
    BagView bv;
    EXPECT_NO_THROW(bv.drawNextTetromino( Bag::getInstance()));
    EXPECT_NO_THROW(bv.drawNextTetromino(Bag::getInstance()));
}
