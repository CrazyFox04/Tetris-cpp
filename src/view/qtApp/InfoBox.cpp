#include "InfoBox.h"
#include <QLabel>
#include <QPainter>
#include "nextTetroWidget.h"
#include "TetrisView.h"


InfoBox::InfoBox(std::shared_ptr<GameController> game, QWidget* parent) : QWidget(parent),game(),
                                                                          score(new QLabel(
                                                                              QString::number(game->getScore()), this)),
                                                                          lines(new QLabel(
                                                                              QString::number(game->getLines()), this)),
                                                                          level(new QLabel(
                                                                              QString::number(game->getLevel()), this)),
                                                                          nextTetroWidget(
                                                                              new NextTetroWidget(game, this)),
                                                                          levelUpLabel("Level Up +1", this),
                                                                          levelUpTimer(this),
                                                                          currentLevel(game->getLevel()) {
    this->game = game;
    connect(dynamic_cast<const QtPrivate::FunctionPointer<void(TetrisView::*)()>::Object *>(parent), SIGNAL(updateQt()),
            this, SLOT(updateQt()));
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    setupInfoWidget(mainLayout, "Score: ", score);
    setupInfoWidget(mainLayout, "Lines: ", lines);
    setupInfoWidget(mainLayout, "Level: ", level);
    QLabel* nextTetroLabel = new QLabel("Coming Next", this);
    nextTetroLabel->setAlignment(Qt::AlignCenter);
    nextTetroLabel->setStyleSheet("QLabel { color : #CAD2C5; font-size : 14px; }");
    mainLayout->addWidget(nextTetroLabel);

    levelUpLabel.setAlignment(Qt::AlignCenter);
    levelUpLabel.setStyleSheet("QLabel { color : #CAD2C5; font-size : 24px; }");
    levelUpLabel.hide();
    connect(&levelUpTimer, &QTimer::timeout, [&] {
        levelUpLabel.hide();
        levelUpTimer.stop();
    });
    mainLayout->addWidget(nextTetroWidget);
    mainLayout->addWidget(&levelUpLabel);
}

void InfoBox::setupInfoWidget(QLayout* layout, const QString&labelText, QLabel* valueLabel) {
    QWidget* widget = new QWidget();
    QHBoxLayout* hLayout = new QHBoxLayout(widget);

    hLayout->setContentsMargins(5, 5, 5, 5);
    hLayout->setSpacing(5);

    QLabel* combinedLabel = new QLabel(labelText + " " + valueLabel->text());
    combinedLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    combinedLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    combinedLabel->setStyleSheet(QString("QLabel { font-size: 14pt; color: #CAD2C5; }"));
    widget->setStyleSheet(
        QString("QWidget { border-radius: 5px; background-color: #354F52; padding: 5px; margin: 0px; }"));

    hLayout->addWidget(combinedLabel);
    layout->addWidget(widget);
    widget->setSizePolicy(QSizePolicy::Preferred,
                          QSizePolicy::Maximum);
}

void InfoBox::updateQt() {
    QString scoreText = QString("Score: %1").arg(game->getScore());
    QString linesText = QString("Lines: %1").arg(game->getLines());
    QString levelText = QString("Level: %1").arg(game->getLevel());
    if (game->getLevel() > currentLevel) {
        currentLevel = game->getLevel();
        levelUpLabel.show();
        levelUpTimer.start(1000);
    }
    foreach(QLabel *label, this->findChildren<QLabel *>()) {
        if (label->text().startsWith("Score:")) {
            label->setText(scoreText);
        }
        else if (label->text().startsWith("Lines:")) {
            label->setText(linesText);
        }
        else if (label->text().startsWith("Level:")) {
            label->setText(levelText);
        }
    }
    nextTetroWidget->update();
}

#include "moc_InfoBox.cpp"
