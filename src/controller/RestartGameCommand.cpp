#include "RestartGameCommand.h"

RestartGameCommand::RestartGameCommand(GameController &controller, Invoker &invoker_, GameView &view_) : gameController(
        controller), invoker(invoker_), view(view_) {}

void RestartGameCommand::execute() {
    invoker.setState(GameState::PLAYING);
    gameController.restart();
    view.draw();
}
