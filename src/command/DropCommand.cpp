//
// Created by Julien Delcombel on 14/03/2024.
//

#include "DropCommand.h"

void DropCommand::execute() {
    gameControler.dropActiveTetromino();
}