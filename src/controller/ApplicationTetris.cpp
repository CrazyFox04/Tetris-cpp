#include <memory>
#include <iostream>

#include "ApplicationTetris.h"
#include "GameController.h"
#include "GameView.h"
#include "Game.h"
#include "Invoker.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveDownCommand.h"
#include "RotateCounterClockwiseCommand.h"
#include "RotateClockwiseCommand.h"
#include "DropCommand.h"
#include "StartGameCommand.h"
#include "QuitGameCommand.h"
#include "RestartGameCommand.h"

ApplicationTetris::ApplicationTetris() : gameController(std::unique_ptr<GameController>(std::make_unique<Game>(game))),
                                            gameView(game){
    initializeCommands();
}

void ApplicationTetris::run() {
    invoker.setState(GameState::MAIN_MENU);
    gameView.displayMenu();

    while (!gameController.isGameOver()) {
        handleInput();
        gameView.draw();
    }
    gameView.displayGameOver();
}

void ApplicationTetris::initializeCommands() {
    invoker.registerCommand("start", std::make_unique<StartGameCommand>(gameController), GameState::MAIN_MENU);
    invoker.registerCommand("a", std::make_unique<RotateCounterClockwiseCommand>(gameController), GameState::PLAYING);
    invoker.registerCommand("z", std::make_unique<DropCommand>(gameController), GameState::PLAYING);
    invoker.registerCommand("e", std::make_unique<RotateClockwiseCommand>(gameController), GameState::PLAYING);
    invoker.registerCommand("q", std::make_unique<MoveLeftCommand>(gameController), GameState::PLAYING);
    invoker.registerCommand("s", std::make_unique<MoveDownCommand>(gameController), GameState::PLAYING);
    invoker.registerCommand("d", std::make_unique<MoveRightCommand>(gameController), GameState::PLAYING);
    invoker.registerCommand("quit", std::make_unique<QuitGameCommand>(gameController), GameState::GAME_OVER);
    invoker.registerCommand("restart", std::make_unique<RestartGameCommand>(gameController), GameState::GAME_OVER);
}

void ApplicationTetris::handleInput() {
    std::string input;
    std::cin >> input;
    try {
        invoker.execute(input);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}