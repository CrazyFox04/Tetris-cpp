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

ApplicationTetris::ApplicationTetris() : gameController(std::make_shared<Game>(GameSettings())),
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
    }
    while (invoker.getState() == GameState::END_GAME);
}

void ApplicationTetris::initializeCommands() {
    invoker.registerCommand("start", std::make_unique<StartGameCommand>(gameController, invoker, gameView),
                            {GameState::MAIN_MENU});
    invoker.registerCommand("settings", std::make_unique<SettingsGameCommand>(*this),
                            {GameState::MAIN_MENU});
    invoker.registerCommand("a", std::make_unique<RotateCounterClockwiseCommand>(*gameController, gameView),
                            {GameState::PLAYING});
    invoker.registerCommand("z", std::make_unique<DropCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("e", std::make_unique<RotateClockwiseCommand>(*gameController, gameView),
                            {GameState::PLAYING});
    invoker.registerCommand("q", std::make_unique<MoveLeftCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("s", std::make_unique<MoveDownCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("d", std::make_unique<MoveRightCommand>(*gameController, gameView), {GameState::PLAYING});
    invoker.registerCommand("quit", std::make_unique<QuitGameCommand>(),
                            {GameState::END_GAME, GameState::MAIN_MENU, GameState::PLAYING});
    invoker.registerCommand("restart", std::make_unique<RestartGameCommand>(*gameController, invoker, gameView),
                            {GameState::END_GAME});
}

void ApplicationTetris::handleInput() {
    std::string input;
    std::cin >> input;
    try {
        invoker.execute(input);
    }
    catch (const std::runtime_error&e) {
        std::cout << e.what() << std::endl;
        handleInput();
    }
}

int ApplicationTetris::askForInt(const std::string&prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            gameView.displayMessage(
                "Invalid input. Please enter a number between " + std::to_string(min) + " and " + std::to_string(max) +
                ".");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return value;
}

void ApplicationTetris::customSettings() {
    int width = askForInt(
        "Enter the width of the board (between 10 and 30): ",
        Board::MIN_BOARD_WIDTH, Board::MAX_BOARD_WIDTH);
    gameSettings.boardWidth = width;
    int height = askForInt(
        "Enter the height of the board (between 10 and 30): ",
        Board::MIN_BOARD_HEIGHT, Board::MAX_BOARD_HEIGHT);
    gameSettings.boardHeight = height;
    int difficulty = askForInt(
        "Enter the difficulty (fill randomly with more or less blocks. 1 for default): ",
        Board::MIN_DIFFICULTY, Board::MAX_DIFFICULTY);
    gameSettings.difficulty = difficulty;
    int level = askForInt(
        "Enter the starting level (sets speed. 1 for default): ",
        1, 20);
    gameSettings.startLevel = level;
    int targetLines = askForInt(
        "Enter the target number of lines to clear (0 to disable): ",
        0, std::numeric_limits<int>::max());
    gameSettings.targetLine = targetLines;
    int targetTime = askForInt(
        "Enter the target time to reach (0 to disable): ",
        0, std::numeric_limits<int>::max());
    gameSettings.targetTime = targetTime;
    int targetScore = askForInt(
        "Enter the target score to reach (0 to disable): ",
        0, std::numeric_limits<int>::max());
    gameSettings.targetScore = targetScore;
    gameController = std::make_unique<Game>(gameSettings);
    gameView.displayMessage( "Press 'start' to begin");
}
