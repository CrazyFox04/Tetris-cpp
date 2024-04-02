#include "MoveDownCommand.h"

MoveDownCommand::MoveDownCommand(GameController& controller) : gameController(controller) {}

void MoveDownCommand::execute() {
    gameController.moveActiveTetromino(Direction::DOWN);
}
