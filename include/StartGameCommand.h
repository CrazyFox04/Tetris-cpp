//
// Created by Julien Delcombel on 30/03/2024.
//

#ifndef TETRIS_STARTGAMECOMMAND_H
#define TETRIS_STARTGAMECOMMAND_H
#include "Command.h"
#include "GameController.h"
#include "Invoker.h"

class StartGameCommand : public Command {
    GameController& gameController;
    Invoker& invoker;
public:
    StartGameCommand(GameController& gameController, Invoker& invoker);
    void execute() override;
};



#endif //TETRIS_STARTGAMECOMMAND_H
