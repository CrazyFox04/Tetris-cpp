#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(GameController& controller, GameView& view_) : gameController(controller), view(view_) {}

void MoveRightCommand::execute() {
    gameController.moveActiveTetromino(Direction::RIGHT);
    view.draw();
}
