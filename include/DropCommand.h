//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"
class DropCommand : public Command {
    GameController& gameController;
public:
    explicit DropCommand(GameController& controller);
    void execute() override;
};
#endif //ROTATECLOCKWISECOMMAND_H
