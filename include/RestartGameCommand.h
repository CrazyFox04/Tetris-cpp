#ifndef TETRIS_RESTARTGAMECOMMAND_H
#define TETRIS_RESTARTGAMECOMMAND_H

#include "Command.h"
#include "GameController.h"

class RestartGameCommand : public Command {
    GameController& gameController;
public:
    explicit RestartGameCommand(GameController& gameController);
    void execute() override;
};

#endif //TETRIS_RESTARTGAMECOMMAND_H
