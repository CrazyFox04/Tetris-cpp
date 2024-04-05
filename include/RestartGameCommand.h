#ifndef TETRIS_RESTARTGAMECOMMAND_H
#define TETRIS_RESTARTGAMECOMMAND_H

#include "Command.h"
#include "GameController.h"
#include "GameView.h"
#include "Invoker.h"

/**
 * @class RestartGameCommand
 * @brief Command for restarting the game.
 *
 * RestartGameCommand is a concrete command that encapsulates the action of restarting
 * the game. It relies on the GameController to actually perform the restarting.
 */
class RestartGameCommand : public Command {
    GameController& gameController; //!< Reference to the game controller.
    Invoker& invoker; //!< Reference to the invoker.
    GameView& view; //!< Reference to the game view.
public:

    /**
     * Constructor for RestartGameCommand.
     * Initializes the command with a reference to the GameController, the Invoker and the GameView.
     * @param gameController Reference to the GameController that controls the game's logic.
     * @param invoker Reference to the invoker that controls the command history.
     * @param view Reference to the GameView that displays the game.
     */
    explicit RestartGameCommand(GameController& gameController, Invoker& invoker, GameView& view_);

    /**
     * Executes the command to restart the game.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //TETRIS_RESTARTGAMECOMMAND_H
