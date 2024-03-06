#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include "Board.h"
#include "Bag.h"
#include "Direction.h"

class Game : public GameControler {
    Board board;
    Bag bag;
    int score;
    int level;
    bool gameOver;

private:
    void updateScore(int points);
    void updateLevel();
    int getPoints(int lines);

public:
    Game();
    void play();
    void moveActiveTetromino(Direction direction) override;
    void rotateActiveTetromino(Direction direction) override;
    void dropActiveTetromino() override;
};


#endif //TETRIS_DEV4_PROJET_GAME_H
