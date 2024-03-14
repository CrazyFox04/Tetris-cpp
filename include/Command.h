//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef COMMAND_H
#define COMMAND_H

#include "GameControler.h"

class Command {
protected:
GameControler & gameControler;
public:
    explicit Command(GameControler gameControler);
    virtual void execute();
};
#endif //COMMAND_H
