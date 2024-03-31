//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Direction.h"
#include "Board.h"
#include "Bag.h"

class GameController {
public:
    virtual ~GameController() = default;

    virtual void start() = 0;

    virtual void restart() = 0;

    virtual void moveActiveTetromino(Direction2D direction) = 0;

    virtual void rotateActiveTetromino(Rotation rotation) = 0;

    virtual void dropActiveTetromino() = 0;

    virtual int getScore() const = 0;

    virtual int getLines() const = 0;

    virtual int getLevel() const = 0;

    virtual Board const& getBoard() const = 0;

    virtual Bag const& getBag() const = 0;

    virtual bool isGameOver() const = 0;
};
#endif //GAMECONTROLLER_H
