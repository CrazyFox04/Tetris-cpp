//
// Created by Julien Delcombel on 23/04/2024.
//
#include "myQtApp.h"
#include "InfoBox.h"
#include "BoardBox.h"
#include <QWidget>
#include <QApplication>

myQtApp::myQtApp(int argc, char* argv[]) : app(argc, argv), window(), mainLayout(), myInfoBox(), myBoardBox() {
}

int myQtApp::start() {
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addLayout(&myInfoBox);
    window.setLayout(&mainLayout);
    window.show();
    return app.exec();
}
