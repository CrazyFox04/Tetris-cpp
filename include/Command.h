#ifndef COMMAND_H
#define COMMAND_H

#include "GameController.h"

class Command {
protected:
    GameController& gameController;
public:
    explicit Command(GameController gameController);
    virtual void execute();
};
#endif //COMMAND_H
