//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_MYQTAPP_H
#define TETRIS_MYQTAPP_H
#include "InfoBox.h"
#include "BoardBox.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QApplication>
#include "Observer.h"
#include "GameController.h"
#include "GameSettings.hpp"

class TetrisView : public QWidget, public Observer {
    QWidget window;
    QHBoxLayout mainLayout;
    InfoBox myInfoBox;
    BoardBox myBoardBox;
    std::shared_ptr<GameController> &game;

public:
    TetrisView(std::shared_ptr<GameController> game);
    int start(QApplication *myQtApp);
    void update() override;
};

#endif //TETRIS_MYQTAPP_H
