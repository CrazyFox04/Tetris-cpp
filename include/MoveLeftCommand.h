//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

class MoveLeftCommand : public Command {
    GameController& gameController;
public:
    explicit MoveLeftCommand(GameController& gameController);
    void execute() override;
};
#endif //ROTATECLOCKWISECOMMAND_H
