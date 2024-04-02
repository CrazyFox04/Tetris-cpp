#include "RotateCounterClockwiseCommand.h"

RotateCounterClockwiseCommand::RotateCounterClockwiseCommand(GameController& controller) : gameController(controller) {}

void RotateCounterClockwiseCommand::execute() {
    gameController.rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
}

