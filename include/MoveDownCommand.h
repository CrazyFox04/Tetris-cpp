//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

class MoveDownCommand : public Command {
    GameController& gameController;
public:
    explicit MoveDownCommand(GameController& gameController);
    void execute() override;
};
#endif //ROTATECLOCKWISECOMMAND_H
