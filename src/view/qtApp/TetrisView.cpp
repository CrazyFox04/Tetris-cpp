#include "InfoBox.h"
#include "BoardBox.h"
#include "TetrisView.h"
#include <QWidget>
#include <iostream>

TetrisView::TetrisView(std::shared_ptr<GameController> game) : mainLayout(new QHBoxLayout(this)), myInfoBox(new InfoBox(game, this)), myBoardBox(new BoardBox(game, this)), game(game) {
    mainLayout->addWidget(myBoardBox);
    mainLayout->addWidget(myInfoBox);
    setLayout(mainLayout);
    setStyleSheet("background-color: #84A98C;");
}

int TetrisView::start(QApplication *myQtApp) {
    show();
    return myQtApp->exec();
}

void TetrisView::update() {
    emit updateQt();
    if (game->isGameOver() || game->isWinner()) {
       endOfGame();
    }
}

void TetrisView::endOfGame() {
    close();
    game->removeObserver(this);
    deleteLater();
}

void TetrisView::closeEvent(QCloseEvent *event) {
   endOfGame();
}


#include "moc_TetrisView.cpp"