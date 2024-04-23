//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_INFOBOX_H
#define TETRIS_INFOBOX_H

#include <QVBoxLayout>

class InfoBox : public QVBoxLayout {
    QHBoxLayout *scoreLayout;
    QHBoxLayout *linesLayout;
    QHBoxLayout *levelLayout;
    QHBoxLayout *nextTetroLayout;

public:
    InfoBox();

};
#endif //TETRIS_INFOBOX_H
