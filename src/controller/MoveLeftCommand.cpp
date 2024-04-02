#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(GameController& controller) : gameController(controller) {}

void MoveLeftCommand::execute() {
    gameController.moveActiveTetromino(Direction::LEFT);
}
