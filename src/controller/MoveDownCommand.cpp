#include "MoveDownCommand.h"

MoveDownCommand::MoveDownCommand(GameController &controller, GameView &view_) : gameController(controller),
                                                                                view(view_) {}

void MoveDownCommand::execute() {
    gameController.moveActiveTetromino(Direction::DOWN);
    view.draw();
}
