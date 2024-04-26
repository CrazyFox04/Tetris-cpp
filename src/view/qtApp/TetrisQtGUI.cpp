//
// Created by Enzo Renard on 26/04/2024.
//
#include <iostream>
#include "TetrisQtGUI.h"
#include "TetrisView.h"

TetrisQtGUI::TetrisQtGUI() : settings(), gameController(){

}

int TetrisQtGUI::run(int argc, char** argv) {
    QApplication myApp = QApplication(argc, argv);
    TetrisView tetris_view = TetrisView(argc, argv);
    tetris_view.start(&myApp);
    return myApp.exec();
}