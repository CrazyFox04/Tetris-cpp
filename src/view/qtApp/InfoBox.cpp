//
// Created by Julien Delcombel on 23/04/2024.
//

#include "InfoBox.h"
#include <QLabel>
#include <QPainter>
#include "nextTetroWidget.h"


InfoBox::InfoBox(std::shared_ptr<GameController> game) : QVBoxLayout(), scoreLayout(), linesLayout(), levelLayout(), nextTetroWidget(), game(){
    this->game = game;
    scoreLayout = new QHBoxLayout();
    linesLayout = new QHBoxLayout();
    levelLayout = new QHBoxLayout();
    nextTetroWidget = new NextTetroWidget();

    QLabel *scoreLabel = new QLabel("Score: ");
    QLabel *score = new QLabel(QString::number(game->getScore()));
    QLabel *linesLabel = new QLabel("Lines: ");
    QLabel *levelLabel = new QLabel("Level: ");

    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(score);
    linesLayout->addWidget(linesLabel);
    levelLayout->addWidget(levelLabel);

    this->addLayout(scoreLayout);
    this->addLayout(linesLayout);
    this->addLayout(levelLayout);
    this->addWidget(nextTetroWidget);
}

void InfoBox::updateMe() {
    nextTetroWidget->update();
    scoreLayout->removeWidget(scoreLayout->itemAt(1)->widget());
    QLabel *score = new QLabel(QString::number(game->getScore()));
    scoreLayout->addWidget(score);
}