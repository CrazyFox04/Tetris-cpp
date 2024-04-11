#include <iostream>
#include <limits>

#include "GameView.h"

GameView::GameView(GameController& controller_) : controller(controller_) {}

void GameView::draw() {
    boardView.drawBoard(controller.getBoard());
    printStats();
    printNext();
}

void GameView::printStats() const{
    std::cout << "Score: " << controller.getScore() << " - ";
    std::cout << "Level: " << controller.getLevel() << " - ";
    std::cout << "Lines: " << controller.getLines() << std::endl;
}

void GameView::printNext() const{
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(controller.getBag());
    std::cout << std::endl;
}

void GameView::displayMenu() const{
    std::cout << "Welcome to Tetris!" << std::endl;
    std::cout << "Press 'start' to begin or 'settings' to configure the game ." << std::endl;
}

void GameView::displaySettings() {
    int width = askWidth();
    controller.setBoardWidth(width);
    int height = askHeight();
    controller.setBoardHeight(height);
    int difficulty = askDifficulty();
    controller.setDifficulty(difficulty);
    int level = askLevel();
    controller.setStartLevel(level);
    int targetLines = askTargetLines();
    controller.setTargetLine(targetLines);
    int targetTime = askTargetTime();
    controller.setTargetTime(targetTime);
    int targetScore = askTargetScore();
    controller.setTargetScore(targetScore);

    std::cout << "Press 'start' to begin" << std::endl;
}

int GameView::askWidth() {
    return askForInt("Enter the width of the board (between 10 and 30): ", Board::MIN_BOARD_WIDTH, Board::MAX_BOARD_WIDTH);
}

int GameView::askHeight() {
    return askForInt("Enter the height of the board (between 10 and 30): ", Board::MIN_BOARD_HEIGHT, Board::MAX_BOARD_HEIGHT);
}

int GameView::askDifficulty() {
    return askForInt("Enter the difficulty (fill randomly with more or less blocks. 1 for default): ", Board::MIN_DIFFICULTY, Board::MAX_DIFFICULTY);
}

int GameView::askLevel() {
    return askForInt("Enter the starting level (sets speed. 1 for default): ", 1, 20);
}

int GameView::askTargetLines() {
    return askForInt("Enter the target number of lines to clear (0 to disable): ", 0, std::numeric_limits<int>::max());
}

int GameView::askTargetTime() {
    return askForInt("Enter the target time to reach (0 to disable): ", 0, std::numeric_limits<int>::max());
}

int GameView::askTargetScore() {
    return askForInt("Enter the target score to reach (0 to disable): ", 0, std::numeric_limits<int>::max());
}

int GameView::askForInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
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
