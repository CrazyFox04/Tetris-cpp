#include "InfoBox.h"
#include "BoardBox.h"
#include "TetrisView.h"
#include <QWidget>
#include <iostream>

TetrisView::TetrisView(std::shared_ptr<GameController> game) : window(), mainLayout(), myInfoBox(game, this), myBoardBox(game, this), game(game) {
    this->game = game;
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addWidget(&myInfoBox);
    window.setLayout(&mainLayout);
}

int TetrisView::start(QApplication *myQtApp) {
    window.show();
    return myQtApp->exec();
}

void TetrisView::update() {
    emit updateQt();
    if (game->isGameOver()) {
        window.close();
    }
}

#include "moc_TetrisView.cpp"