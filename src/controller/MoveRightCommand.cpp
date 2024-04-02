#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(GameController& controller) : gameController(controller) {}

void MoveRightCommand::execute() {
    gameController.moveActiveTetromino(Direction::RIGHT);
}
