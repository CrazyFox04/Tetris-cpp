#include "TetrisConfiguration.h"
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include "Game.h"
#include "TetrisView.h"
#include <QCloseEvent>


TetrisConfiguration::TetrisConfiguration(GameSettings* settings) : settings(settings), layout(new QFormLayout(this)),
                                                                   boardWidthLabel(new QLabel("Board Width", this)),
                                                                   boardHeightLabel(new QLabel("Board Height", this)),
                                                                   startLevelLabel(new QLabel("Start Level", this)),
                                                                   targetLineLabel(new QLabel("Target Line", this)),
                                                                   targetTimeLabel(new QLabel("Target Time", this)),
                                                                   targetScoreLabel(new QLabel("Target Score", this)),
                                                                   difficultyLabel(new QLabel("Difficulty", this)),
                                                                   boardWidthComboBox(new QComboBox(this)),
                                                                   boardHeightComboBox(new QComboBox(this)),
                                                                   startLevelComboBox(new QComboBox(this)),
                                                                   difficultyComboBox(new QComboBox(this)),
                                                                   targetLineLineEdit(
                                                                       new QLineEdit(QString::number(0), this)),
                                                                   targetTimeLineEdit(
                                                                       new QLineEdit(QString::number(0), this)),
                                                                   targetScoreLineEdit(
                                                                       new QLineEdit(QString::number(0), this)),
                                                                   startButton(new QPushButton("Start", this)) {
    setWindowTitle("Tetris Configuration");
    configureWindow();
    setLayout(layout);
}

void TetrisConfiguration::configureWindow() {
    resize(300, 200);
    createLineEdits();
    addFields();
    createButtons();
    setValues();
}

void TetrisConfiguration::setValues() {
    boardWidthComboBox->setCurrentText(QString::number(settings->boardWidth));
    boardHeightComboBox->setCurrentText(QString::number(settings->boardHeight));
    startLevelComboBox->setCurrentText(QString::number(settings->startLevel));
    targetLineLineEdit->setText(QString::number(settings->targetLine));
    targetTimeLineEdit->setText(QString::number(settings->targetTime));
    targetScoreLineEdit->setText(QString::number(settings->targetScore));
    difficultyComboBox->setCurrentText(QString::number(settings->difficulty));
}

void TetrisConfiguration::closeWidget() {
    settings->difficulty = difficultyComboBox->currentText().toInt();
    settings->boardWidth = boardWidthComboBox->currentText().toInt();
    settings->boardHeight = boardHeightComboBox->currentText().toInt();
    settings->startLevel = startLevelComboBox->currentText().toInt();
    settings->targetLine = targetLineLineEdit->text().toInt();
    settings->targetTime = targetTimeLineEdit->text().toInt();
    settings->targetScore = targetScoreLineEdit->text().toInt();
    close();
}

void TetrisConfiguration::createButtons() {
    QString buttonStyle =
            "QPushButton { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }";
    startButton->setStyleSheet(buttonStyle);
    layout->addRow(startButton);
    connect(startButton, &QPushButton::clicked, this, &TetrisConfiguration::closeWidget);
}

void TetrisConfiguration::addFields() {
    layout->addRow(boardWidthLabel, boardWidthComboBox);
    layout->addRow(boardHeightLabel, boardHeightComboBox);
    layout->addRow(startLevelLabel, startLevelComboBox);
    layout->addRow(targetLineLabel, targetLineLineEdit);
    layout->addRow(targetTimeLabel, targetTimeLineEdit);
    layout->addRow(targetScoreLabel, targetScoreLineEdit);
    layout->addRow(difficultyLabel, difficultyComboBox);
}

void TetrisConfiguration::createLineEdits() {
    QString lineEditStyle =
            "QLineEdit { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }";

    for (int w = 10; w <= 30; ++w) boardWidthComboBox->addItem(QString::number(w));
    boardWidthComboBox->setStyleSheet(lineEditStyle);

    for (int h = 10; h <= 30; ++h) boardHeightComboBox->addItem(QString::number(h));
    boardHeightComboBox->setStyleSheet(lineEditStyle);
    boardHeightComboBox->setCurrentIndex(10);

    for (int lvl = 1; lvl <= Game::MAX_START_LEVEL; lvl++) startLevelComboBox->addItem(QString::number(lvl));
    startLevelComboBox->setStyleSheet(lineEditStyle);

    targetLineLineEdit->setStyleSheet(lineEditStyle);
    targetTimeLineEdit->setStyleSheet(lineEditStyle);
    targetScoreLineEdit->setStyleSheet(lineEditStyle);

    for (int diff = 1; diff <= 20; diff++) difficultyComboBox->addItem(QString::number(diff));
    difficultyComboBox->setStyleSheet(lineEditStyle);
}


int TetrisConfiguration::start(QApplication* myQtApp) {
    show();
    return myQtApp->exec();
}

#include "moc_TetrisConfiguration.cpp"
