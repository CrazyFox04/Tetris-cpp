//
// Created by Julien Delcombel on 14/03/2024.
//

#include "MoveLeftCommand.h"
#include "Direction.h"

void MoveLeftCommand::execute() {
    gameController.moveActiveTetromino(Direction::LEFT);
}