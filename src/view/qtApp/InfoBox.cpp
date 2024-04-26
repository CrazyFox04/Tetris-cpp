//
// Created by Julien Delcombel on 23/04/2024.
//

#include "InfoBox.h"
#include <QLabel>


InfoBox::InfoBox() : QVBoxLayout(), scoreLayout(), linesLayout(), levelLayout(), nextTetroLayout(){
    scoreLayout = new QHBoxLayout();
    linesLayout = new QHBoxLayout();
    levelLayout = new QHBoxLayout();
    nextTetroLayout = new QHBoxLayout();

    QLabel *scoreLabel = new QLabel("Score: ");
    QLabel *linesLabel = new QLabel("Lines: ");
    QLabel *levelLabel = new QLabel("Level: ");
    QLabel *nextTetroLabel = new QLabel("Next Tetromino: ");

    scoreLayout->addWidget(scoreLabel);
    linesLayout->addWidget(linesLabel);
    levelLayout->addWidget(levelLabel);
    nextTetroLayout->addWidget(nextTetroLabel);

    this->addLayout(scoreLayout);
    this->addLayout(linesLayout);
    this->addLayout(levelLayout);
    this->addLayout(nextTetroLayout);
}