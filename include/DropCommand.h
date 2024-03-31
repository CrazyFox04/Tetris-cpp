//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef DROPCOMMAND_H
#define DROPCOMMAND_H
#include "Command.h"
#include "GameController.h"
class DropCommand : public Command {
    GameController& gameController;
public:
    explicit DropCommand(GameController& controller);
    void execute() override;
};
#endif //DROPCOMMAND_H
