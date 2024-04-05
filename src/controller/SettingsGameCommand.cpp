#include "SettingsGameCommand.h"

SettingsGameCommand::SettingsGameCommand(GameView &view)
        : gameView(view) {}

void SettingsGameCommand::execute() {
    gameView.displaySettings();
}
