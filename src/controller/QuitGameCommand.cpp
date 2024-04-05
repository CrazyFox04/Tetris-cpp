#include "QuitGameCommand.h"
#include <cstdlib>

#include "Bag.h"

QuitGameCommand::QuitGameCommand() {}
void QuitGameCommand::execute() {
    free(&Bag::getInstance());
    exit(0);
}