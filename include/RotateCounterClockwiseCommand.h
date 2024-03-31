#ifndef ROTATECOUNTERCLOCKWISECOMMAND_H
#define ROTATECOUNTERCLOCKWISECOMMAND_H
#include "Command.h"
#include "GameController.h"

/**
 * @class RotateCounterClockwiseCommand
 * @brief Command for rotating the active tetromino counter-clockwise.
 *
 * RotateCounterClockwiseCommand is a concrete command that encapsulates the action of rotating
 * the active tetromino counter-clockwise in the game. It relies on the GameController to actually
 * perform the rotation.
 */
class RotateCounterClockwiseCommand : public Command {
    GameController& gameController; //!< Reference to the game controller.
public:

    /**
     * Constructor for RotateCounterClockwiseCommand.
     * Initializes the command with a reference to the GameController.
     * @param gameController Reference to the GameController that controls the game's logic.
     */
    explicit RotateCounterClockwiseCommand(GameController& gameController);

    /**
     * Executes the command to rotate the active tetromino counter-clockwise.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //ROTATECOUNTERCLOCKWISECOMMAND_H
