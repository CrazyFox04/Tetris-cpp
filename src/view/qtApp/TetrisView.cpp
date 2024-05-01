//
// Created by Julien Delcombel on 23/04/2024.
//
#include "TetrisView.h"
#include "InfoBox.h"
#include "BoardBox.h"
#include <QWidget>
#include <iostream>

TetrisView::TetrisView(std::shared_ptr<GameController> game) : window(), mainLayout(), myInfoBox(game), myBoardBox(game), game(game) {
    this->game = game;
}

int TetrisView::start(QApplication *myQtApp) {
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addWidget(&myInfoBox);
    window.setLayout(&mainLayout);
    window.show();
    return myQtApp->exec();
}

void TetrisView::update() {
    myBoardBox.update();
    myInfoBox.updateMe();
}