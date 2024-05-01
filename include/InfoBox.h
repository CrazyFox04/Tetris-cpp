//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_INFOBOX_H
#define TETRIS_INFOBOX_H

#include "GameController.h"
#include <QString>
#include <QLabel>
#include <QHBoxLayout>

class InfoBox : public QWidget {
    QLabel *score;
    QLabel *lines;
    QLabel *level;
    QWidget *nextTetroWidget;
    std::shared_ptr<GameController> game;

    void setupInfoWidget(QLayout *layout, const QString &labelText, QLabel *valueLabel);

public:
    InfoBox(std::shared_ptr<GameController> game);

    void updateMe();
};

#endif //TETRIS_INFOBOX_H
