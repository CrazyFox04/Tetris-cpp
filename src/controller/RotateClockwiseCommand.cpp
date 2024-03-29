#include "RotateClockwiseCommand.h"

RotateClockwiseCommand::RotateClockwiseCommand(GameController& controller) : gameController(controller) {}

void RotateClockwiseCommand::execute() {
    gameController.rotateActiveTetromino(Rotation::CLOCKWISE);
}
