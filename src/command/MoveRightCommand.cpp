//
// Created by Julien Delcombel on 14/03/2024.
//

#include "MoveRightCommand.h"

void MoveRightCommand::execute() {
    gameControler.moveActiveTetromino(Direction::RIGHT);
}