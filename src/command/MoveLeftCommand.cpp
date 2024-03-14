//
// Created by Julien Delcombel on 14/03/2024.
//

#include "MoveLeftCommand.h"

void MoveLeftCommand::execute() {
    gameControler.moveActiveTetromino(Direction::LEFT);
}