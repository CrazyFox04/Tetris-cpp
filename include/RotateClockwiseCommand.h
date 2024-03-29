#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

class RotateClockwiseCommand : public Command {
    GameController& gameController;
public:
    explicit RotateClockwiseCommand(GameController& gameController);
    void execute() override;
};

#endif //ROTATECLOCKWISECOMMAND_H
