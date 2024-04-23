//
// Created by Enzo Renard on 12/04/2024.
//
#include "QLabel"
#include "MainWindow.h"
#include "Game.h"
#include <QGridLayout>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>

int start(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    std::shared_ptr<GameController> myController = std::make_shared<Game>();
    MainWindow myWindow;
    myWindow.show();
    return app.exec();
}