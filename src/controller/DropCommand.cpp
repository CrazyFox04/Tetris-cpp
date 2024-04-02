#include "DropCommand.h"

DropCommand::DropCommand(GameController& controller, GameView& view_) : gameController(controller), view(view_) {}

void DropCommand::execute() {
    gameController.dropActiveTetromino();
    view.draw();
}
