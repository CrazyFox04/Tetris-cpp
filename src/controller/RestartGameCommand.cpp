#include "RestartGameCommand.h"

RestartGameCommand::RestartGameCommand(GameController& controller, Invoker& invoker, GameView& view_) : gameController(controller), invoker(invoker), view(view_) {}

void RestartGameCommand::execute() {
    invoker.setState(GameState::PLAYING);
    gameController.restart();
    view.draw();
}
