#include "QuitGameCommand.h"

QuitGameCommand::QuitGameCommand(GameController& controller) : gameController(controller) {}

void QuitGameCommand::execute() {
    exit(0);
}