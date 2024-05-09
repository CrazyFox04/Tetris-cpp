//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_INFOBOX_H
#define TETRIS_INFOBOX_H

#include "GameController.h"
#include <QString>
#include <QLabel>
#include <QTimer>
#include <QHBoxLayout>

class InfoBox : public QWidget {
    Q_OBJECT
    QLabel* score;
    QLabel* lines;
    QLabel* level;
    QLabel levelUpLabel;
    QTimer levelUpTimer;
    QWidget* nextTetroWidget;
    std::shared_ptr<GameController> game;
    int currentLevel;

    void setupInfoWidget(QLayout* layout, const QString&labelText, QLabel* valueLabel);

public:
    InfoBox(std::shared_ptr<GameController> game, QWidget* parent = nullptr);

public slots:
    void updateQt();
};

#endif //TETRIS_INFOBOX_H
