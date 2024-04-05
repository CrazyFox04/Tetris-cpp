#ifndef MOVELEFTCOMMAND_H
#define MOVELEFTCOMMAND_H

#include "Command.h"
#include "GameController.h"
#include "GameView.h"

/**
 * @class MoveLeftCommand
 * @brief Command for moving the active tetromino to the left.
 *
 * MoveLeftCommand is a concrete command that encapsulates the action of moving
 * the active tetromino one unit to the left in the game. It relies on the GameController
 * to actually perform the movement.
 */
class MoveLeftCommand : public Command {
    GameController &gameController; //!< Reference to the game controller.
    GameView &view; //!< Reference to the game view.
public:

    /**
     * Constructor for MoveLeftCommand.
     * Initializes the command with a reference to the GameController and GameView.
     * @param gameController Reference to the GameController that controls the game's logic.
     * @param view Reference to the GameView that displays the game.
     */
    explicit MoveLeftCommand(GameController &gameController, GameView &view);

    /**
     * Executes the command to move the active tetromino to the left.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //MOVELEFTCOMMAND_H
