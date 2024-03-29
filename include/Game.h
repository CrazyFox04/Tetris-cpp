#ifndef TETRIS_DEV4_PROJET_GAME_H
#define TETRIS_DEV4_PROJET_GAME_H

#include "GameController.h"
#include <vector>
#include "Observable.h"
#include "Observer.h"
#include "Board.h"
#include "Bag.h"
#include "Direction.h"
#include <memory>

class Game : public Observable, public GameController {
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
    void start() override;
    void moveActiveTetromino(Direction2D direction);
    void rotateActiveTetromino(Rotation rotation);
    void dropActiveTetromino();
    bool isOccupied(int row, int col) const;
    void notifyObservers() override;
    void addObserver(Observer& observer) override;
    void removeObserver(int pos) override;
    int getScore() const override;
    int getLines() const override;
    int getLevel() const override;
    Board const & getBoard() const override;
    Bag const & getBag() const override;
    bool isGameOver() const override;
};


#endif //TETRIS_DEV4_PROJET_GAME_H
