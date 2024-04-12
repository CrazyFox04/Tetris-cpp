#include <iostream>
#include <limits>

#include "GameView.h"

#include "ApplicationTetris.h"

GameView::GameView(GameController&controller_) : controller(controller_) {
}

void GameView::draw() {
    boardView.drawBoard(controller.getBoard());
    printStats();
    printNext();
}

void GameView::printStats() const {
    std::cout << "Score: " << controller.getScore() << " - ";
    std::cout << "Level: " << controller.getLevel() << " - ";
    std::cout << "Lines: " << controller.getLines() << std::endl;
}

void GameView::printNext() const {
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(controller.getBag());
    std::cout << std::endl;
}

void GameView::displayMenu() const {
    std::cout << "Welcome to Tetris!" << std::endl;
    std::cout << "Press 'start' to begin or 'settings' to configure the game ." << std::endl;
}

void GameView::displaySettings() {
    int width = ApplicationTetris::askForInt(
        "Enter the width of the board (between 10 and 30): ",
        Board::MIN_BOARD_WIDTH, Board::MAX_BOARD_WIDTH);
    controller.setBoardWidth(width);
    int height = ApplicationTetris::askForInt(
        "Enter the height of the board (between 10 and 30): ",
        Board::MIN_BOARD_HEIGHT, Board::MAX_BOARD_HEIGHT);
    controller.setBoardHeight(height);
    int difficulty = ApplicationTetris::askForInt(
        "Enter the difficulty (fill randomly with more or less blocks. 1 for default): ",
        Board::MIN_DIFFICULTY, Board::MAX_DIFFICULTY);
    controller.setDifficulty(difficulty);
    int level = ApplicationTetris::askForInt(
        "Enter the starting level (sets speed. 1 for default): ",
        1, 20);
    controller.setStartLevel(level);
    int targetLines = ApplicationTetris::askForInt(
        "Enter the target number of lines to clear (0 to disable): ",
        0, std::numeric_limits<int>::max());
    controller.setTargetLine(targetLines);
    int targetTime = ApplicationTetris::askForInt(
        "Enter the target time to reach (0 to disable): ",
        0, std::numeric_limits<int>::max());
    controller.setTargetTime(targetTime);
    int targetScore = ApplicationTetris::askForInt(
        "Enter the target score to reach (0 to disable): ",
        0, std::numeric_limits<int>::max());
    controller.setTargetScore(targetScore);

    std::cout << "Press 'start' to begin" << std::endl;
}

void GameView::displayGameOver() const {
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}

void GameView::displayVictory() const {
    std::cout << "Congratulations! You won!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}
