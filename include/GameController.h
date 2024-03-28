//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMECONTROLER_H
#define GAMECONTROLER_H

#include "Direction.h"

class GameController {
public:
    virtual ~GameController() = default;
    virtual void moveActiveTetromino(Direction2D direction) = 0;
    virtual void rotateActiveTetromino(Rotation rotation) = 0;
    virtual void dropActiveTetromino() = 0;
};
#endif //GAMECONTROLER_H
