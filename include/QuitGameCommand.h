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

public:

    /**
     * Executes the command to quit the game.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //TETRIS_QUITGAMECOMMAND_H
