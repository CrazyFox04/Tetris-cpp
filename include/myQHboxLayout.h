//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_MYQHBOXLAYOUT_H
#define TETRIS_MYQHBOXLAYOUT_H

#include <QHboxLayout>
#include <QPushButton>
#include <QLabel>

class myQHboxLayout : public QHBoxLayout {
private:
    QPushButton pb;
    QLabel label;
public:
    myQHboxLayout();

};

#endif //TETRIS_MYQHBOXLAYOUT_H
