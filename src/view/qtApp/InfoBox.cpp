//
// Created by Julien Delcombel on 23/04/2024.
//

#include "InfoBox.h"
#include <QLabel>
#include <QPainter>
#include "nextTetroWidget.h"


InfoBox::InfoBox(std::shared_ptr<GameController> game) : score(new QLabel(QString::number(game->getScore()))),
                                                         lines(new QLabel(QString::number(game->getLines()))),
                                                         level(new QLabel(QString::number(game->getLevel()))),
                                                         nextTetroWidget(), game() {
    this->game = game;
    QHBoxLayout *scoreLayout = new QHBoxLayout();
    QHBoxLayout *linesLayout = new QHBoxLayout();
    QHBoxLayout *levelLayout = new QHBoxLayout();
    NextTetroWidget *nextTetroWidget = new NextTetroWidget();

    QLabel *scoreLabel = new QLabel("Score: ");
    QLabel *linesLabel = new QLabel("Lines: ");
    QLabel *levelLabel = new QLabel("Level: ");

    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(score);
    linesLayout->addWidget(linesLabel);
    linesLayout->addWidget(lines);
    levelLayout->addWidget(levelLabel);
    levelLayout->addWidget(level);

    this->addLayout(scoreLayout);
    this->addLayout(linesLayout);
    this->addLayout(levelLayout);
    this->addWidget(nextTetroWidget);
}

void InfoBox::updateMe() {
    //nextTetroWidget->update();
    score->setText(QString::number(game->getScore()));
    lines->setText(QString::number(game->getLines()));
    level->setText(QString::number(game->getLevel()));
}