//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMECONTROLER_H
#define GAMECONTROLER_H

#include "Direction.h"

class GameControler {
public:
    virtual void moveActiveTetromino(Direction direction);
    virtual void rotateActiveTetromino(Direction direction);
    virtual void dropActiveTetromino();
};
#endif //GAMECONTROLER_H
