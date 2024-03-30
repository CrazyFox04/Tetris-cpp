#ifndef TETRIS_QUITGAMECOMMAND_H
#define TETRIS_QUITGAMECOMMAND_H

#include "Command.h"
#include "GameController.h"

class QuitGameCommand : public Command {
    GameController& gameController;
public:
    explicit QuitGameCommand(GameController& gameController);
    void execute() override;
};

#endif //TETRIS_QUITGAMECOMMAND_H
