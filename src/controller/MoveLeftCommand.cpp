#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand(GameController &controller, GameView &view_) : gameController(controller),
                                                                                view(view_) {}

void MoveLeftCommand::execute() {
    gameController.moveActiveTetromino(Direction::LEFT);
    view.draw();
}
