//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef COMMAND_H
#define COMMAND_H

#include "GameController.h"

class Command {
protected:
    GameController&gameControler;
public:
    explicit Command(GameController gameController);
    virtual void execute();
};
#endif //COMMAND_H
