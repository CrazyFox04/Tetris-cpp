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
        while (!gameController->isGameOver()) {
            handleInput();
        }
        invoker.setState(GameState::GAME_OVER);
        gameView.displayGameOver();
    } while (playerWantToRestart());
    handleInput();
}

bool ApplicationTetris::playerWantToRestart() {
    std::string input = "";
    do {
        input = askUser("Do you want to play another Game ? (y/n)");
    } while (input != "y" && input != "n");
    return input == "y";
}

void ApplicationTetris::initializeCommands() {
    invoker.registerCommand("start", std::make_unique<StartGameCommand>(*gameController, invoker, gameView),
                            GameState::MAIN_MENU);
    invoker.registerCommand("settings", std::make_unique<SettingsGameCommand>(*gameController, gameView),
                            GameState::MAIN_MENU);
    invoker.registerCommand("a", std::make_unique<RotateCounterClockwiseCommand>(*gameController, gameView), GameState::PLAYING);
    invoker.registerCommand("z", std::make_unique<DropCommand>(*gameController, gameView), GameState::PLAYING);
    invoker.registerCommand("e", std::make_unique<RotateClockwiseCommand>(*gameController, gameView), GameState::PLAYING);
    invoker.registerCommand("q", std::make_unique<MoveLeftCommand>(*gameController, gameView), GameState::PLAYING);
    invoker.registerCommand("s", std::make_unique<MoveDownCommand>(*gameController, gameView), GameState::PLAYING);
    invoker.registerCommand("d", std::make_unique<MoveRightCommand>(*gameController, gameView), GameState::PLAYING);
    invoker.registerCommand("quit", std::make_unique<QuitGameCommand>(*gameController), GameState::GAME_OVER);
    invoker.registerCommand("restart", std::make_unique<RestartGameCommand>(*gameController, gameView), GameState::GAME_OVER);
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

std::string ApplicationTetris::askUser(std::string question) {
    std::cout << question << std::endl;
    std::string input;
    std::cin >> input;
    return input;
}
