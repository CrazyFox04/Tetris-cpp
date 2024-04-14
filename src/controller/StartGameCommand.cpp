#include "StartGameCommand.h"

StartGameCommand::StartGameCommand(std::shared_ptr<GameController> controller, Invoker& invoker_, GameView& view_)
                    : gameController(controller), invoker(invoker_), view(view_) {
}

void StartGameCommand::execute() {
    invoker.setState(GameState::PLAYING);
    gameController->start();
    view.draw();
}
