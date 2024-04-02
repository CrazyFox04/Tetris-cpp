//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef DROPCOMMAND_H
#define DROPCOMMAND_H
#include "Command.h"
#include "GameController.h"
#include "GameView.h"

/**
 * @class DropCommand
 * @brief Command to handle the 'drop' action in a game.
 *
 * DropCommand is a concrete implementation of the Command interface. It encapsulates
 * the action of 'dropping' an element in a game, which typically means instantly
 * moving a game piece to its final position. This command is linked with a
 * GameController that it communicates with to execute the action.
 */
class DropCommand : public Command {
    // Reference to GameController to delegate the execution logic of the command.
    GameController &gameController;
    // Reference to the GameView to delegate the display of the command.
    GameView &view;

public:
    /**
     * Constructor for DropCommand.
     * @param controller Reference to GameController which this command will interact with.
     */
    explicit DropCommand(GameController &controller, GameView &view);

    /**
     * Execute the drop action.
     *
     * When executed, this command will interact with the GameController to perform
     * the drop action in the game. The specifics of this action are determined by
     * the GameController's implementation.
     */
    void execute() override;
};

#endif //DROPCOMMAND_H
