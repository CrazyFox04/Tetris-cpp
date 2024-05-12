#include "InfoBox.h"
#include "BoardBox.h"
#include "TetrisView.h"
#include <QWidget>
#include <iostream>

TetrisView::TetrisView(std::shared_ptr<GameController> game) : mainLayout(new QHBoxLayout()), myInfoBox(new InfoBox(game, this)), myBoardBox(new BoardBox(game, this)), game(game) {
    mainLayout->addWidget(myBoardBox);
    mainLayout->addWidget(myInfoBox);
    setLayout(mainLayout);
}

int TetrisView::start(QApplication *myQtApp) {
    show();
    return myQtApp->exec();
}

void TetrisView::update() {
    emit updateQt();
    if (game->isGameOver() || game->isWinner()) {
        close();
    }
}


#include "moc_TetrisView.cpp"