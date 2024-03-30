#include "RestartGameCommand.h"

RestartGameCommand::RestartGameCommand(GameController& controller) : gameController(controller) {}

void RestartGameCommand::execute() {
    gameController.restartGame();
}
