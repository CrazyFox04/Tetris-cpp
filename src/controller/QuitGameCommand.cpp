#include "QuitGameCommand.h"
#include <cstdlib>

QuitGameCommand::QuitGameCommand(GameController& controller) : gameController(controller) {}

void QuitGameCommand::execute() {
    exit(0);
}