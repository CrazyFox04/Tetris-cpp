//
// Created by Julien Delcombel on 23/03/2024.
//

#include <gtest/gtest.h>
#include "GameView.h"

TEST(GameViewTest, drawGameInterface) {
    Game g;
    GameView gv(g);
    EXPECT_NO_THROW(gv.drawGameInterface());
}