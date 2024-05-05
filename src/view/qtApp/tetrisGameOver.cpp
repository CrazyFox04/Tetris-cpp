//
// Created by Enzo Renard on 26/04/2024.
//
#include "tetrisGameOver.h"
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

TetrisGameOver::TetrisGameOver(std::shared_ptr<GameController> game, QWidget* parent) : QWidget(parent), game(game),
    layout(nullptr), gameOverLabel(nullptr), detailsLabel(nullptr), buttonLayout(nullptr), restartButton(nullptr),
    quitButton(nullptr) {
    this->game = game;
    configureWindow();
    createItems();
}

TetrisGameOver::~TetrisGameOver() {
    delete layout;
    delete gameOverLabel;
    delete detailsLabel;
    delete buttonLayout;
    delete restartButton;
    delete quitButton;
}

void TetrisGameOver::configureWindow() {
    setWindowTitle("Tetris End Of Game");
    setFixedSize(300, 200);
}

void TetrisGameOver::createItems() {
    layout = new QVBoxLayout(this);

    if (game->isGameOver()) {
        gameOverLabel = new QLabel("Game Over !!!");
    }
    else {
        gameOverLabel = new QLabel("You've given up !!!");
    }
    gameOverLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(gameOverLabel);

    detailsLabel = new QLabel();
    if (game->isWinner()) {
        detailsLabel->setText("Congratulations! You Won!");
    }
    else {
        detailsLabel->setText(QString("Score: %1\nLines Completed: %2").arg(game->getScore()).arg(game->getLines()));
    }
    detailsLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(detailsLabel);

    buttonLayout = new QHBoxLayout();
    restartButton = new QPushButton("Restart");
    quitButton = new QPushButton("Quit");
    restartButton->setStyleSheet(
        "QPushButton { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }");
    quitButton->setStyleSheet(
        "QPushButton { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }");
    buttonLayout->addWidget(restartButton);
    buttonLayout->addWidget(quitButton);
    connect(restartButton, &QPushButton::clicked, this, &TetrisGameOver::restartGame);
    connect(quitButton, &QPushButton::clicked, this, &TetrisGameOver::quitGame);
    layout->addLayout(buttonLayout);
}

void TetrisGameOver::restartGame() {
    game->restart();
    close();
}

void TetrisGameOver::quitGame() {
    game->restart();
    close();
    exit(0);
}

int TetrisGameOver::start(QApplication* myQtApp) {
    show();
    return myQtApp->exec();
}
