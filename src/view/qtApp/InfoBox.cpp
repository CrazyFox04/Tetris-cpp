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
    QLayout *mainLayout = new QVBoxLayout();
    this->setLayout(mainLayout);

    setupInfoWidget(mainLayout, "Score: ", score);
    setupInfoWidget(mainLayout, "Lines: ", lines);
    setupInfoWidget(mainLayout, "Level: ", level);

    //mainLayout->addWidget(nextTetroWidget);
}

void InfoBox::setupInfoWidget(QLayout *layout, const QString &labelText, QLabel *valueLabel) {
    QWidget *widget = new QWidget();
    QHBoxLayout *hLayout = new QHBoxLayout(widget);

    hLayout->setContentsMargins(5, 5, 5, 5);
    hLayout->setSpacing(5);

    QLabel *combinedLabel = new QLabel(labelText + " " + valueLabel->text());
    combinedLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    combinedLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    QString borderColor = "#0f380f";
    QString backgroundColor = "#9bbc0f";
    combinedLabel->setStyleSheet(QString("QLabel { font-size: 12pt; color: %1; }").arg(borderColor));
    widget->setStyleSheet(
            QString("QWidget { border: 2px solid %1; border-radius: 5px; "
                    "background-color: %2; padding: 5px; margin: 0px; }").arg(
                    borderColor, backgroundColor));

    hLayout->addWidget(combinedLabel);
    layout->addWidget(widget);
    widget->setSizePolicy(QSizePolicy::Preferred,
                          QSizePolicy::Maximum); // Set the size policy to maximum for the widget
}

void InfoBox::updateMe() {
    QString scoreText = QString("Score: %1").arg(game->getScore());
    QString linesText = QString("Lines: %1").arg(game->getLines());
    QString levelText = QString("Level: %1").arg(game->getLevel());

    foreach (QLabel *label, this->findChildren<QLabel *>()) {
        if (label->text().startsWith("Score:")) {
            label->setText(scoreText);
        } else if (label->text().startsWith("Lines:")) {
            label->setText(linesText);
        } else if (label->text().startsWith("Level:")) {
            label->setText(levelText);
        }
    }
}