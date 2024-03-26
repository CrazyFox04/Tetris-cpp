//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef GAMECONTROLER_H
#define GAMECONTROLER_H

#include "Direction.h"

class GameController {
public:
<<<<<<< HEAD:include/GameController.h
    virtual void moveActiveTetromino(Direction direction);
    virtual void rotateActiveTetromino(Rotation rotation);
    virtual void dropActiveTetromino();
=======
    virtual ~GameControler() = default;
    virtual void moveActiveTetromino(Direction2D direction) = 0;
    virtual void rotateActiveTetromino(Rotation rotation) = 0;
    virtual void dropActiveTetromino() = 0;
>>>>>>> 8aa5246:include/GameControler.h
};
#endif //GAMECONTROLER_H
