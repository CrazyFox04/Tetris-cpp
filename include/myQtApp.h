//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_MYQTAPP_H
#define TETRIS_MYQTAPP_H
#include "InfoBox.h"
#include "BoardBox.h"
#include <QApplication>
class myQtApp {
    QApplication app;
    QWidget window;
    QHBoxLayout mainLayout;
    InfoBox myInfoBox;
    BoardBox myBoardBox;

public:
    myQtApp(int argc, char *argv[]);
    int start();
};

#endif //TETRIS_MYQTAPP_H
