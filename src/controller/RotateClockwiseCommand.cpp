#include "RotateClockwiseCommand.h"

RotateClockwiseCommand::RotateClockwiseCommand(GameController &controller, GameView &view_) : gameController(
        controller), view(view_) {}

void RotateClockwiseCommand::execute() {
    gameController.rotateActiveTetromino(Rotation::CLOCKWISE);
    view.draw();
}
