//
// Created by Julien Delcombel on 14/03/2024.
//

#include "MoveDownCommand.h"

void MoveDownCommand::execute() {
    gameController.moveActiveTetromino(Direction::DOWN);
}
