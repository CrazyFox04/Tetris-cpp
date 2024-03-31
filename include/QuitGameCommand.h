#ifndef TETRIS_QUITGAMECOMMAND_H
#define TETRIS_QUITGAMECOMMAND_H

#include "Command.h"
#include "GameController.h"

/**
 * @class QuitGameCommand
 * @brief Command for quitting the game.
 *
 * QuitGameCommand is a concrete command that encapsulates the action of quitting
 * the game. It relies on the GameController to actually perform the quitting.
 */
class QuitGameCommand : public Command {
    GameController& gameController; //!< Reference to the game controller.
public:

    /**
     * Constructor for QuitGameCommand.
     * Initializes the command with a reference to the GameController.
     * @param gameController Reference to the GameController that controls the game's logic.
     */
    explicit QuitGameCommand(GameController& gameController);

    /**
     * Executes the command to quit the game.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //TETRIS_QUITGAMECOMMAND_H
