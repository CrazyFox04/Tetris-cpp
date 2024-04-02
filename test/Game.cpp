//
// Created by Enzo Renard on 29/03/2024.
//
#include <gtest/gtest.h>
#include "Game.h"

TEST(Game, ctor) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    ASSERT_EQ(game.getBoard().getWidth(), 10);
    ASSERT_EQ(game.getBoard().getHeight(), 20);
    ASSERT_EQ(game.getLevel(), 1);
    ASSERT_EQ(game.getLines(), 0);
    ASSERT_EQ(game.getScore(), 0);
}

TEST(Game, play_isGameOver) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    game.start();
    ASSERT_FALSE(game.isGameOver());
}

TEST(Game, moveActiveTetrominoWithoutStarting) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    ASSERT_NO_THROW(game.moveActiveTetromino(Direction::DOWN));
    ASSERT_EQ(game.getBag().getNumberOfTetrominos(), Bag::getInstance().getAvailableTetrominos().size());
}

TEST(Game, rotateActiveTetrominoWithoutstarting) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    ASSERT_NO_THROW(game.rotateActiveTetromino(Rotation::CLOCKWISE));
    ASSERT_EQ(game.getBag().getNumberOfTetrominos(), Bag::getInstance().getAvailableTetrominos().size());
}

TEST(Game, dropActiveTetrominoWithoutStarting) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    ASSERT_NO_THROW(game.dropActiveTetromino());
    ASSERT_EQ(game.getBag().getNumberOfTetrominos(), Bag::getInstance().getAvailableTetrominos().size());
}

TEST(Game, moveAndDropAddNewTetro) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    game.start();
    game.dropActiveTetromino();
    game.dropActiveTetromino();
    game.moveActiveTetromino(Direction::DOWN);
    ASSERT_EQ(game.getBoard().getTetrominos().size(), 3);
}

TEST(Game, moveActiveTetromino) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    game.start();
    game.moveActiveTetromino(Direction::DOWN);
    ASSERT_EQ(game.getBoard().getTetrominos().size(), 1);
}

TEST(Game, rotateActiveTetromino) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    game.start();
    game.rotateActiveTetromino(Rotation::CLOCKWISE);
    ASSERT_EQ(game.getBoard().getTetrominos().size(), 1);
}

TEST(Game, dropActiveTetromino) {
    Game game = Game(10, 20, 1, 1, 10, 10, 10);
    game.start();
    game.dropActiveTetromino();
    ASSERT_EQ(game.getBoard().getTetrominos().size(), 2);
}