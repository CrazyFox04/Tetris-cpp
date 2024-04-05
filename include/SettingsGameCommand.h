#ifndef TETRIS_SETTINGSGAMECOMMAND_H
#define TETRIS_SETTINGSGAMECOMMAND_H

#include "Command.h"
#include "GameView.h"


/**
 * @class SettingsGameCommand
 * @brief Command for setting the game.
 *
 * SettingsGameCommand is a concrete command that encapsulates the action of setting
 * the game. It relies on the GameController and the GameView to actually perform the setting.
 */
class SettingsGameCommand : public Command {
    GameView &gameView; //!< Reference to the game view.
public:

    /**
     * Constructor for SettingsGameCommand.
     * Initializes the command with a reference to the GameController and the GameView.
     * @param gameController Reference to the GameController that controls the game's logic.
     * @param gameView Reference to GameView that controls the game's view.
     */
    SettingsGameCommand(GameView &gameView);

    /**
     * Executes the command to start the game.
     * Delegates the action to the GameController.
     */
    void execute() override;
};

#endif //TETRIS_SETTINGSGAMECOMMAND_H
