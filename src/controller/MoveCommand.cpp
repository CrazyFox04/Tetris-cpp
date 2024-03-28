#include "MoveCommand.h"

MoveCommand::MoveCommand(GameController& controller, Direction2D dir) : gameController(controller), direction(dir) {}

void MoveCommand::execute() {
    gameController.moveActiveTetromino(direction);
}
