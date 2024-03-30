//
// Created by Julien Delcombel on 30/03/2024.
//
#include "StartGameCommand.h"

StartGameCommand::StartGameCommand(GameController& controller, Invoker& invoker)
                    : gameController(controller), invoker(invoker) {}

void StartGameCommand::execute() {
    invoker.setState(GameState::PLAYING);
    gameController.startGame();
}
