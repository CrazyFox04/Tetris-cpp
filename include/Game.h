#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include "Observable.h"
#include "Invoker.h"
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "RotateClockwiseCommand.h"
#include "RotateCounterClockwiseCommand.h"
#include "DropCommand.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include "GameControler.h"

class Game : public GameControler, public Observable {
    Invoker invoker;
    GameControler* gameControler;
    Board board;
    Bag bag;
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
    void play();
    void moveActiveTetromino(Direction2D direction) override;
    void rotateActiveTetromino(Rotation rotation) override;
    void dropActiveTetromino() override;
};


#endif //TETRIS_DEV4_PROJET_GAME_H
