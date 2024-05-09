//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_MYQTAPP_H
#define TETRIS_MYQTAPP_H
#include "BoardBox.h"
#include "InfoBox.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QApplication>
#include "Observer.h"
#include "GameController.h"
#include "GameSettings.hpp"

class TetrisView : public QWidget, public Observer {
    Q_OBJECT
    QWidget window;
    QHBoxLayout mainLayout;
    InfoBox myInfoBox;
    BoardBox myBoardBox;
    std::shared_ptr<GameController>&game;

public:
    TetrisView(std::shared_ptr<GameController> game);

    ~TetrisView() override = default;

    int start(QApplication* myQtApp);

    void update() override;

signals:
    void updateQt();
};

#endif //TETRIS_MYQTAPP_H
