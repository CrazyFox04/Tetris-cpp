#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include "Observable.h"
#include "Invoker.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include "GameControler.h"

class Game : public GameControler, public Observable {
    Invoker invoker;
    GameControler* gameControler;
    Board board;
    Bag& bag;
    int score;
    int level;
    bool gameOver;

private:
    void updateScore(int linesCleared, int dropDistance);
    void updateLevel();
    int getPoints(int lines, int dropDistance) const;
    void initializeCommands();
public:
    Game();
    ~Game();
    void play();
    void moveActiveTetromino(Direction2D direction) override;
    void rotateActiveTetromino(Rotation rotation) override;
    void dropActiveTetromino() override;
    void isFree(int row, int col);
};


#endif //TETRIS_DEV4_PROJET_GAME_H
