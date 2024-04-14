#include "SettingsGameCommand.h"

SettingsGameCommand::SettingsGameCommand (ApplicationTetris& application_tetris)
        : application_tetris(application_tetris) {}

void SettingsGameCommand::execute() {
    application_tetris.customSettings();
}
