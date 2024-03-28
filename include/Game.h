#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include <vector>
#include "Observable.h"
#include "Observer.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include <memory>

class Game : public Observable {
    std::vector<std::shared_ptr<Observer>> observers;
    Board board;
    Bag& bag;
    int currentScore;
    int currentLevel;
    int currentLine;
    int currentTime;
    int targetLine;
    int targetTime;
    int targetScore;
    bool gameOver;

private:
    void updateScore(int linesCleared, int dropDistance);
    void updateLevel();
    int getPoints(int lines, int dropDistance) const;
    void initializeCommands();
public:
    Game(int width, int height, int difficulty, int startLevel, int targetLine, int targetTime, int targetScore);
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
