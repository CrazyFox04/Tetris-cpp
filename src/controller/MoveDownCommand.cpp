#include "MoveDownCommand.h"
#include "Direction.h"

MoveDownCommand::MoveDownCommand(GameController& controller) : gameController(controller) {}

void MoveDownCommand::execute() {
    gameController.moveActiveTetromino(Direction::DOWN);
}
