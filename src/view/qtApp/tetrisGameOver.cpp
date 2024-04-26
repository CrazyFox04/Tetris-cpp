//
// Created by Enzo Renard on 26/04/2024.
//
#include "tetrisGameOver.h"
#include <QWidget>
#include <QApplication>

TetrisGameOver::TetrisGameOver() {
    window.setWindowTitle("Tetris Game Over");
    window.resize(300, 200);
    window.show();
}

int TetrisGameOver::start(QApplication *myQtApp) {
    return myQtApp->exec();
}