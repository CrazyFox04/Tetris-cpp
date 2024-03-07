//
// Created by Julien Delcombel on 07/03/2024.
//

#include "Game.h"

/**
 * class Game : public GameControler {
    Board board;
    Bag bag;
    int score;
    int level;
    bool gameOver;
*/

Game::Game() : score(0), level(1), gameOver(false) {
}

void Game::play() {
    while (!gameOver) {
        board.addTetromino(bag.getNext());
    }
}

void Game::moveActiveTetromino(Direction2D direction) {
    board.moveActiveTetromino(direction);
}

void Game::rotateActiveTetromino(Direction direction) {
    board.rotateActiveTetromino(direction);
}

void Game::dropActiveTetromino() {
    board.moveActiveTetromino(Direction::DOWN);
}

void Game::updateScore(int points) {
    score += points;
}

void Game::updateLevel() {
    level++;
}

int Game::getPoints(int lines) {
    return lines * level * 100;
}