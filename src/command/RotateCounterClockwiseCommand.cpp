//
// Created by Julien Delcombel on 14/03/2024.
//

#include "RotateCounterClockwiseCommand.h"

void rotateCounterClockwiseCommand::execute() {
    gameController.rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
}