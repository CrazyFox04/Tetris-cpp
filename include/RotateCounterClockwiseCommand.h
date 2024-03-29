#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

class RotateCounterClockwiseCommand : public Command {
    GameController& gameController;
public:
    explicit RotateCounterClockwiseCommand(GameController& gameController);
    void execute() override;
};

#endif //ROTATECLOCKWISECOMMAND_H
