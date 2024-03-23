//
// Created by Julien Delcombel on 14/03/2024.
//

#include "RotateClockwiseCommand.h"

void rotateClockwiseCommand::execute() {
    gameController.rotateActiveTetromino(Rotation::CLOCKWISE);
}