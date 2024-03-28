//
// Created by Julien Delcombel on 28/03/2024.
//

#ifndef TETRIS_MOVECOMMAND_H
#define TETRIS_MOVECOMMAND_H

#include "Command.h"
#include "GameController.h"
#include "Direction.h"

class MoveCommand : public Command {
    GameController& gameController;
    Direction2D direction;
public:
    MoveCommand(GameController& controller, Direction2D dir);
    void execute() override;
};

#endif //TETRIS_MOVECOMMAND_H
