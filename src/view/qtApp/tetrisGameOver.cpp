#include "tetrisGameOver.h"
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

TetrisGameOver::TetrisGameOver(std::shared_ptr<GameController> game, QWidget *parent)
        : QWidget(parent), game(game), layout(new QVBoxLayout(this)),
          gameOverLabel(new QLabel(this)), detailsLabel(new QLabel(this)),
          buttonLayout(new QHBoxLayout), restartButton(new QPushButton("Restart", this)),
          quitButton(new QPushButton("Quit", this)) {
    configureWindow();
    createItems();
    setLayout(layout);
    updateItems();
}

void TetrisGameOver::configureWindow() {
    setWindowTitle("Tetris End Of Game");
    setFixedSize(500, 300);
    setStyleSheet("background-color: #84A98C;");
}

void TetrisGameOver::createItems() {
    QString boutonStyle = "QPushButton { border-radius: 5px; background-color: #354F52; padding: 5px; color: #CAD2C5}";
    gameOverLabel->setAlignment(Qt::AlignCenter);
    gameOverLabel->setStyleSheet("QLabel { font-size: 24px; color : #2F3E46;}");
    layout->addWidget(gameOverLabel);

    detailsLabel->setAlignment(Qt::AlignCenter);
    detailsLabel->setStyleSheet("QLabel { font-size: 16px; color : #2F3E46;}");
    layout->addWidget(detailsLabel);

    restartButton->setStyleSheet(boutonStyle);
    quitButton->setStyleSheet(boutonStyle);
    restartButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    quitButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    buttonLayout->addWidget(restartButton);
    buttonLayout->addWidget(quitButton);
    buttonLayout->setSpacing(20);
    buttonLayout->setContentsMargins(10, 0, 10, 0);

    layout->addLayout(buttonLayout);

    connect(restartButton, &QPushButton::clicked, this, &TetrisGameOver::restartGame);
    connect(quitButton, &QPushButton::clicked, this, &TetrisGameOver::quitGame);
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
    } else {
        detailsLabel->setText(QString("Score: %1\nLines Completed: %2").arg(game->getScore()).arg(game->getLines()));
    }
}

void TetrisGameOver::restartGame() {
    game->restart();
    close();
    deleteLater();
}

void TetrisGameOver::quitGame() {
    game->restart();
    close();
    deleteLater();
    exit(0);
}

int TetrisGameOver::start(QApplication *myQtApp) {
    updateItems();
    show();
    return myQtApp->exec();
}