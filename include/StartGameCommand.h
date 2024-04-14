#ifndef TETRIS_STARTGAMECOMMAND_H
#define TETRIS_STARTGAMECOMMAND_H

#include "Command.h"
#include "GameController.h"
#include "Invoker.h"
#include "GameView.h"

/**
 * @class StartGameCommand
 * @brief Command for starting the game.
 *
 * StartGameCommand is a concrete command that encapsulates the action of starting
 * the game. It relies on the GameController to actually perform the starting.
 */
class StartGameCommand : public Command {
    std::shared_ptr<GameController> gameController; //!< Reference to the game controller.
    Invoker &invoker; //!< Reference to the invoker.
    GameView &view; //!< Reference to the game view.
public:

    /**
     * Constructor for StartGameCommand.
     * Initializes the command with a reference to the GameController.
     * @param gameController Reference to the GameController that controls the game's logic.
     * @param invoker Reference to the invoker that controls the commands.
     */
    StartGameCommand(std::shared_ptr<GameController> gameController, Invoker &invoker, GameView &gameView);

    /**
     * Executes the command to start the game.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //TETRIS_STARTGAMECOMMAND_H
