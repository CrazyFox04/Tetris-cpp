#include "RotateCounterClockwiseCommand.h"

RotateCounterClockwiseCommand::RotateCounterClockwiseCommand(GameController &controller, GameView &view_)
        : gameController(controller), view(view_) {}

void RotateCounterClockwiseCommand::execute() {
    gameController.rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
    view.draw();
}

