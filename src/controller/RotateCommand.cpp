#include "RotateCommand.h"

RotateCommand::RotateCommand(GameController& controller, Rotation rot) : gameController(controller), rotation(rot) {}

void RotateCommand::execute() {
    gameController.rotateActiveTetromino(rotation);
}
