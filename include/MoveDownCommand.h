//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef MOVEDOWNCOMMAND_H
#define MOVEDOWNCOMMAND_H
#include "Command.h"
#include "GameController.h"
#include "GameView.h"

/**
 * @class MoveDownCommand
 * @brief Command for moving the active tetromino downwards.
 *
 * MoveDownCommand is a concrete command that encapsulates the action of moving
 * the active tetromino one unit downwards in the game. It relies on the GameController
 * to actually perform the movement.
 */
class MoveDownCommand : public Command {
    GameController& gameController; //!< Reference to the game controller.
    GameView& view; //!< Reference to the game view.
public:

    /**
     * Constructor for MoveDownCommand.
     * Initializes the command with a reference to the GameController.
     * @param gameController Reference to the GameController that controls the game's logic.
     */
    explicit MoveDownCommand(GameController& gameController, GameView& view);

    /**
     * Executes the command to move the active tetromino downwards.
     * Delegates the action to the GameController.
     */
    void execute() override;
};
#endif //MOVEDOWNCOMMAND_H
