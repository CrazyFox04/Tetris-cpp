#include "tetrisGameOver.h"
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

TetrisGameOver::TetrisGameOver(std::shared_ptr<GameController> game, QWidget* parent) : QWidget(parent), game(game),
    layout(new QVBoxLayout(this)), gameOverLabel( new QLabel()), detailsLabel(new QLabel()), buttonLayout(new QHBoxLayout()), restartButton(new QPushButton("Restart")),
    quitButton(new QPushButton("Quit")) {
    configureWindow();
    createItems();
    setLayout(layout);
}

void TetrisGameOver::configureWindow() {
    setWindowTitle("Tetris End Of Game");
    setFixedSize(500, 300);
}

void TetrisGameOver::createItems() {
    gameOverLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(gameOverLabel);

    detailsLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(detailsLabel);

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

void TetrisGameOver::updateItems() {
    if (game->isGameOver()) {
        gameOverLabel->setText("Game Over !!!");
    } else {
        if (game->isWinner()) {
            gameOverLabel->setText("Congratulations! You've won !!!");
        } else {
            gameOverLabel->setText("You've given up !!!");
        }
    }
    if (game->isWinner()) {
        int totalSeconds = game->getTime();
        std::chrono::seconds seconds(totalSeconds);

        auto hours = std::chrono::duration_cast<std::chrono::hours>(seconds);
        seconds -= std::chrono::duration_cast<std::chrono::seconds>(hours);

        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(seconds);
        seconds -= std::chrono::duration_cast<std::chrono::seconds>(minutes);

        detailsLabel->setText(QString("You've finished the game in %1 hours, %2 minutes and %3 seconds!")
                              .arg(hours.count())
                              .arg(minutes.count())
                              .arg(seconds.count()));
    }
    else {
        detailsLabel->setText(QString("Score: %1\nLines Completed: %2").arg(game->getScore()).arg(game->getLines()));
    }
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
    updateItems();
    show();
    return myQtApp->exec();
}
