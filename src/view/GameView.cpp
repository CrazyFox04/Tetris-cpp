#include "GameView.h"

GameView::GameView(GameController& controller_) : controller(controller_) {}

void GameView::draw() {
    //Display the board game
    boardView.drawBoard(controller.getBoard());

    //Display the score, level and lines
    std::cout << "Score: " << controller.getScore() << std::endl;
    std::cout << "Level: " << controller.getLevel() << std::endl;
    std::cout << "Lines: " << controller.getLines() << std::endl;

    //Display the next tetromino
    std::cout << "Next Tetromino: " << std::endl;
    bagView.drawNextTetromino(controller.getBag());
    std::cout << std::endl;
}

void GameView::displayMenu() {
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
    int width = 0;
    do {
        std::cout << "Enter the width of the board (between 5 and 20, 0 for default): ";
        std::cin >> width;
        if (width < 5 || width > 20) {
            std::cout << "The width must be between 5 and 20." << std::endl;
        }
    } while (width < 5 || width > 20);
    return width;
}

int GameView::askHeight() {
    int height = 0;
    do {
        std::cout << "Enter the height of the board (between 10 and 30, 0 for default): ";
        std::cin >> height;
        if (height < 10 || height > 30) {
            std::cout << "The height must be between 10 and 30." << std::endl;
        }
    } while (height < 10 || height > 30);
    return height;
}

int GameView::askDifficulty() {
    int level = 0;
    do {
        std::cout << "Enter the difficulty of the game (Fills the board with more or less blocks, 1 for default): ";
        std::cin >> level;
        if (level < 1 || level > 20) {
            std::cout << "The level must be between 1 and 20." << std::endl;
        }
    } while (level < 1 || level > 20);
    return level;
}

int GameView::askLevel() {
    int level = 0;
    do {
        std::cout << "Enter the starting level (sets the speed accordingly. 1 to 20, 1 for default): ";
        std::cin >> level;
        if (level < 1 || level > 20) {
            std::cout << "The level must be between 1 and 20." << std::endl;
        }
    } while (level < 1 || level > 20);
    return level;
}

int GameView::askTargetLines() {
    int target =0;
    do {
        std::cout << "Enter the target number of lines to clear (0 to disable): ";
        std::cin >> target;
        if (target < 0) {
            std::cout << "The target must be greater than 0." << std::endl;
        }
    } while (target < 0);
    return target;
}

int GameView::askTargetTime() {
    int target =0;
    do {
        std::cout << "Enter the target time to survive in seconds (0 to disable): ";
        std::cin >> target;
        if (target < 0) {
            std::cout << "The target must be greater than 0." << std::endl;
        }
    } while (target < 0);
    return target;
}

int GameView::askTargetScore() {
    int target =0;
    do {
        std::cout << "Enter the target score to reach (0 to disable): ";
        std::cin >> target;
        if (target < 0) {
            std::cout << "The target must be greater than 0." << std::endl;
        }
    } while (target < 0);
    return target;
}

void GameView::displayGameOver() {
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}

void GameView::displayVictory() {
    std::cout << "Congratulations! You won!" << std::endl;
    std::cout << "Your score: " << controller.getScore() << std::endl;
    std::cout << "Press 'restart' to start again or 'quit' to exit." << std::endl;
}
