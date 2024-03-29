#include "DropCommand.h"

DropCommand::DropCommand(GameController& controller) : gameController(controller) {}

void DropCommand::execute() {
    gameController.dropActiveTetromino();
}
