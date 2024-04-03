#include <memory>
#include <iostream>

#include "ApplicationTetris.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveDownCommand.h"
#include "RotateCounterClockwiseCommand.h"
#include "RotateClockwiseCommand.h"
#include "DropCommand.h"
#include "StartGameCommand.h"
#include "SettingsGameCommand.h"
#include "QuitGameCommand.h"
#include "RestartGameCommand.h"

ApplicationTetris::ApplicationTetris() :
        gameController(std::unique_ptr<Game>(std::make_unique<Game>(Game()))),
        gameView(*gameController) {
    initializeCommands();
}

void ApplicationTetris::run() {
    invoker.setState(GameState::MAIN_MENU);
    gameView.displayMenu();
    do {
        handleInput();
        while (!gameController->isGameOver() && !gameController->isWinner()) {
            handleInput();
        }
        invoker.setState(GameState::END_GAME);
        if (gameController->isGameOver()) {
            gameView.displayGameOver();
        }
        if (gameController->isWinner()) {
            gameView.displayVictory();
        }
    } while (invoker.getState() == GameState::END_GAME);
}

void ApplicationTetris::initializeCommands() {
    invoker.registerCommand("start", std::make_unique<StartGameCommand>(*gameController, invoker, gameView),
                            {GameState::MAIN_MENU});
    invoker.registerCommand("settings", std::make_unique<SettingsGameCommand>(*gameController, gameView),
                            {GameState::MAIN_MENU});
    invoker.registerCommand("a", std::make_unique<RotateCounterClockwiseCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("z", std::make_unique<DropCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("e", std::make_unique<RotateClockwiseCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("q", std::make_unique<MoveLeftCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("s", std::make_unique<MoveDownCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("d", std::make_unique<MoveRightCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("quit", std::make_unique<QuitGameCommand>(*gameController), {GameState::END_GAME, GameState::MAIN_MENU, GameState::PLAYING});
    invoker.registerCommand("restart", std::make_unique<RestartGameCommand>(*gameController, invoker, gameView), {GameState::END_GAME});
}

void ApplicationTetris::handleInput() {
    std::string input;
    std::cin >> input;
    try {
        invoker.execute(input);
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        handleInput();
    }
}