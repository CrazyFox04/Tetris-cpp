//
// Created by Enzo Renard on 26/04/2024.
//
#include "tetrisGameOver.h"
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

TetrisGameOver::TetrisGameOver(std::shared_ptr<GameController> game, QWidget* parent) : QWidget(parent), game(game) {
    this->game = game;
    configureWindow();
    createItems();
    show();
}

void TetrisGameOver::configureWindow() {
    setWindowTitle("Tetris Game Over");
    setFixedSize(300, 200);
}

void TetrisGameOver::createItems() {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* gameOverLabel = new QLabel("Game Over !!!");
    gameOverLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(gameOverLabel);

    QLabel* detailsLabel = new QLabel();
    if (game->isWinner()) {
        detailsLabel->setText("Congratulations! You Won!");
    } else {
        detailsLabel->setText(QString("Score: %1\nLines Completed: %2").arg(game->getScore()).arg(game->getLines()));
    }
    detailsLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(detailsLabel);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton *restartButton = new QPushButton("Restart");
    QPushButton *quitButton = new QPushButton("Quit");
    restartButton->setStyleSheet("QPushButton { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }");
    quitButton->setStyleSheet("QPushButton { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }");
    buttonLayout->addWidget(restartButton);
    buttonLayout->addWidget(quitButton);
    //connect(restartButton, &QPushButton::clicked, this, &TetrisGameOver::restartGame);
    //connect(quitButton, &QPushButton::clicked, this, &TetrisGameOver::quitGame);
    layout->addLayout(buttonLayout);

}

int TetrisGameOver::start(QApplication *myQtApp) {
    return myQtApp->exec();
}