#ifndef ROTATECOUNTERCLOCKWISECOMMAND_H
#define ROTATECOUNTERCLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

class RotateCounterClockwiseCommand : public Command {
    GameController& gameController;
public:
    explicit RotateCounterClockwiseCommand(GameController& gameController);
    void execute() override;
};

#endif //ROTATECOUNTERCLOCKWISECOMMAND_H
