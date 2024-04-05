#include "QuitGameCommand.h"
#include <cstdlib>

QuitGameCommand::QuitGameCommand() {}
void QuitGameCommand::execute() {
    exit(0);
}