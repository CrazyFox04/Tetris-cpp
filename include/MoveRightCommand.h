//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

class MoveRightCommand : public Command {
    GameController& gameController;
public:
    explicit MoveRightCommand(GameController& gameController);
    void execute() override;
};
#endif //ROTATECLOCKWISECOMMAND_H
