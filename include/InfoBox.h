//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_INFOBOX_H
#define TETRIS_INFOBOX_H

#include <QHBoxLayout>
class InfoBox : public QVBoxLayout {
    QHBoxLayout *scoreLayout;
    QHBoxLayout *linesLayout;
    QHBoxLayout *levelLayout;
    QWidget *nextTetroWidget;

public:
    InfoBox();
};
#endif //TETRIS_INFOBOX_H
