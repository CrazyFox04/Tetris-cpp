//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H

#include "Command.h"

class MoveRightCommand : public Command {
public:
    void execute() override;
};
#endif //ROTATECLOCKWISECOMMAND_H
