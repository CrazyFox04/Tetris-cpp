//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef MOVEDOWNCOMMAND_H
#define MOVEDOWNCOMMAND_H
#include "Command.h"
#include "GameController.h"

class MoveDownCommand : public Command {
    GameController& gameController;
public:
    explicit MoveDownCommand(GameController& gameController);
    void execute() override;
};
#endif //MOVEDOWNCOMMAND_H
