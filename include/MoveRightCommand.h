#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H
#include "Command.h"
#include "GameController.h"
#include "GameView.h"

/**
 * @class MoveRightCommand
 * @brief Command for moving the active tetromino to the right.
 *
 * MoveRightCommand is a concrete command that encapsulates the action of moving
 * the active tetromino one unit to the right in the game. It relies on the GameController
 * to actually perform the movement.
 */
class MoveRightCommand : public Command {
    GameController& gameController; //!< Reference to the game controller.
    GameView& view; //!< Reference to the game view.
public:

    /**
     * Constructor for MoveRightCommand.
     * Initializes the command with a reference to the GameController.
     * @param gameController Reference to the GameController that controls the game's logic.
     */
    explicit MoveRightCommand(GameController& gameController, GameView& view);

    /**
     * Executes the command to move the active tetromino to the right.
     * Delegates the action to the GameController.
     */
    void execute() override;
};
#endif //MOVERIGHTCOMMAND_H
