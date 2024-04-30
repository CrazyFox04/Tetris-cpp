//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_INFOBOX_H
#define TETRIS_INFOBOX_H
#include "GameController.h"
#include <QString>
#include <QHBoxLayout>
class InfoBox : public QVBoxLayout {
    QHBoxLayout *scoreLayout;
    QHBoxLayout *linesLayout;
    QHBoxLayout *levelLayout;
    QWidget *nextTetroWidget;
    std::shared_ptr<GameController> game;

public:
    InfoBox(std::shared_ptr<GameController> game);
    void updateMe();
};
#endif //TETRIS_INFOBOX_H
