//
// Created by Julien Delcombel on 23/04/2024.
//

#include "InfoBox.h"
#include <QLabel>
#include <QPainter>
#include "nextTetroWidget.h"


InfoBox::InfoBox() : QVBoxLayout(), scoreLayout(), linesLayout(), levelLayout(), nextTetroWidget(){
    scoreLayout = new QHBoxLayout();
    linesLayout = new QHBoxLayout();
    levelLayout = new QHBoxLayout();
    nextTetroWidget = new NextTetroWidget();

    QLabel *scoreLabel = new QLabel("Score: ");
    QLabel *linesLabel = new QLabel("Lines: ");
    QLabel *levelLabel = new QLabel("Level: ");

    scoreLayout->addWidget(scoreLabel);
    linesLayout->addWidget(linesLabel);
    levelLayout->addWidget(levelLabel);

    this->addLayout(scoreLayout);
    this->addLayout(linesLayout);
    this->addLayout(levelLayout);
    this->addWidget(nextTetroWidget);
}
