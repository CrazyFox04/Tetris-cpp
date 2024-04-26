//
// Created by Enzo Renard on 26/04/2024.
//
#include "TetrisConfiguration.h"
#include <QWidget>
#include <QApplication>

TetrisConfiguration::TetrisConfiguration() {
    window.setWindowTitle("Tetris Configuration");
    window.resize(300, 200);
    window.show();
}

int TetrisConfiguration::start(QApplication *myQtApp) {
    return myQtApp->exec();
}