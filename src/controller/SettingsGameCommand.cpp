#include "SettingsGameCommand.h"

SettingsGameCommand::SettingsGameCommand(GameController& controller, GameView& view)
: gameController(controller), gameView(view) {}

void SettingsGameCommand::execute() {
    gameView.displaySettings();
}
