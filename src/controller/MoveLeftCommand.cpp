#include "MoveLeftCommand.h"
#include "Direction.h"

MoveLeftCommand::MoveLeftCommand(GameController& controller) : gameController(controller) {}

void MoveLeftCommand::execute() {
    gameController.moveActiveTetromino(Direction::LEFT);
}
