//
// Created by Julien Delcombel on 23/04/2024.
//
#include "myQtApp.h"
#include "InfoBox.h"
#include "BoardBox.h"
#include <QWidget>
#include <QApplication>

int myQtApp::start(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget w;
    InfoBox myInfoBox;
    BoardBox myBoardBox;
    QHBoxLayout mainLayout;
    QWidget brol;
    brol.setLayout(&myInfoBox);
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addWidget(&brol);
    w.setLayout(&mainLayout);
    w.show();
    return app.exec();
}