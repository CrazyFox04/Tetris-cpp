#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include "Observable.h"
#include "Invoker.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include "GameController.h"

class Game : public Observable {
    Invoker invoker;
    Board board;
    Bag& bag;
    int score;
    int lines;
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
    void moveActiveTetromino(Direction2D direction);
    void rotateActiveTetromino(Rotation rotation);
    void dropActiveTetromino();
    void isFree(int row, int col);
    virtual void notifyObservers();
    virtual void addObserver(Observer& observer);
    virtual void removeObserver(int pos);
    Board& getBoard() const;
    Bag& getBag() const;
    int getScore() const;
    int getLevel() const;
    int getLines() const;
};


#endif //TETRIS_DEV4_PROJET_GAME_H
