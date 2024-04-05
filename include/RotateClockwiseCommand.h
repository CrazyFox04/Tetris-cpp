#ifndef ROTATECLOCKWISECOMMAND_H
#define ROTATECLOCKWISECOMMAND_H

#include "Command.h"
#include "GameController.h"
#include "GameView.h"

/**
 * @class RotateClockwiseCommand
 * @brief Command for rotating the active tetromino clockwise.
 *
 * RotateClockwiseCommand is a concrete command that encapsulates the action of rotating
 * the active tetromino clockwise in the game. It relies on the GameController to actually
 * perform the rotation.
 */
class RotateClockwiseCommand : public Command {
    GameController &gameController; //!< Reference to the game controller.
    GameView &view; //!< Reference to the game view.
public:

    /**
     * Constructor for RotateClockwiseCommand.
     * Initializes the command with a reference to the GameController and GameView.
     * @param gameController Reference to the GameController that controls the game's logic.
     * @param view Reference to the GameView that displays the game.
     */
    explicit RotateClockwiseCommand(GameController &gameController, GameView &view);

    /**
     * Executes the command to rotate the active tetromino clockwise.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //ROTATECLOCKWISECOMMAND_H
