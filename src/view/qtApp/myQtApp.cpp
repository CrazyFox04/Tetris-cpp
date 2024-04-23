//
// Created by Julien Delcombel on 23/04/2024.
//
#include "myQtApp.h"
#include "myQHboxLayout.h"
#include <QApplication>
#include <QLabel>
#include "QPushButton"

int myQtApp::start(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget w;
    myQHboxLayout firstQHBoxLayout;
    myQHboxLayout myOtherQHboxLayout2;
    w.setLayout(&firstQHBoxLayout);
    w.show();
    return app.exec();
}