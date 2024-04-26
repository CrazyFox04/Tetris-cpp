//
// Created by Julien Delcombel on 23/04/2024.
//
#include "myQtApp.h"
#include "InfoBox.h"
#include "BoardBox.h"
#include <QWidget>
#include <QApplication>

myQtApp::myQtApp(int argc, char* argv[]) : app(argc, argv), window(), myInfoBox(), myBoardBox(), mainLayout(), brol() {
}

int myQtApp::start() {
    brol.setLayout(&myInfoBox);
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addWidget(&brol);
    window.setLayout(&mainLayout);
    window.show();
    return app.exec();
}
