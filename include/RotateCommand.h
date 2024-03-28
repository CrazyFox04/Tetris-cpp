#ifndef TETRIS_ROTATECOMMAND_H
#define TETRIS_ROTATECOMMAND_H

#include "Command.h"
#include "GameController.h"
#include "Direction.h"

class RotateCommand : public Command {
    GameController& gameController;
    Rotation rotation;
public:
    RotateCommand(GameController& controller, Rotation rot);
    void execute() override;
};

#endif //TETRIS_ROTATECOMMAND_H
