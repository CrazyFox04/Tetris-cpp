#include "RestartGameCommand.h"

RestartGameCommand::RestartGameCommand(GameController& controller, GameView& view_) : gameController(controller), view(view_) {}

void RestartGameCommand::execute() {
    gameController.restart();
    view.draw();
}
