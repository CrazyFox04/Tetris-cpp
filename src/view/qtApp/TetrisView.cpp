//
// Created by Julien Delcombel on 23/04/2024.
//
#include "TetrisView.h"
#include "InfoBox.h"
#include "BoardBox.h"
#include <QWidget>

TetrisView::TetrisView(int argc, char* argv[]) : window(), mainLayout(), myInfoBox(), myBoardBox() {
}

int TetrisView::start(QApplication *myQtApp) {
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addLayout(&myInfoBox);
    window.setLayout(&mainLayout);
    window.show();
    return myQtApp->exec();
}
