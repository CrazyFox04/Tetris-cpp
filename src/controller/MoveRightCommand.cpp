#include "MoveRightCommand.h"
#include "Direction.h"

MoveRightCommand::MoveRightCommand(GameController& controller) : gameController(controller) {}

void MoveRightCommand::execute() {
    gameController.moveActiveTetromino(Direction::RIGHT);
}
