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


TetrisConfiguration::TetrisConfiguration(GameSettings* settings) : settings(settings) {
    window.setWindowTitle("Tetris Configuration");
    configureWindow();
    window.setLayout(this);
    window.show();
}


void TetrisConfiguration::configureWindow() {
    window.resize(300, 200);
    createLabels();
    createLineEdits();
    addFields();
    createButtons();
    window.show();
}

void TetrisConfiguration::close() {
    settings->difficulty = difficultyComboBox->currentText().toInt();
    //settings->difficulty = difficultyLineEdit->text().toInt();
    settings->boardWidth = boardWidthComboBox->currentText().toInt();
    //settings->boardWidth = boardWidthLineEdit->text().toInt();
    settings->boardHeight = boardHeightComboBox->currentText().toInt();
    //settings->boardHeight = boardHeightLineEdit->text().toInt();
    settings->startLevel = startLevelComboBox->currentText().toInt();
    //settings->startLevel = startLevelLineEdit->text().toInt();
    settings->targetLine = targetLineLineEdit->text().toInt();
    settings->targetTime = targetTimeLineEdit->text().toInt();
    settings->targetScore = targetScoreLineEdit->text().toInt();
    window.close();
}

void TetrisConfiguration::createButtons() {
    QPushButton* startButton = new QPushButton("Start");
    QString buttonStyle = "QPushButton { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }";
    startButton->setStyleSheet(buttonStyle);
    addRow(startButton);
    connect(startButton, &QPushButton::clicked, this, &TetrisConfiguration::close);
}

void TetrisConfiguration::addFields() {
    addRow(boardWidthLabel, boardWidthComboBox);
    addRow(boardHeightLabel, boardHeightComboBox);
    addRow(startLevelLabel, startLevelComboBox);
    addRow(targetLineLabel, targetLineLineEdit);
    addRow(targetTimeLabel, targetTimeLineEdit);
    addRow(targetScoreLabel, targetScoreLineEdit);
    addRow(difficultyLabel, difficultyComboBox);
}

void TetrisConfiguration::createLabels() {
    boardWidthLabel = new QLabel("Board Width");
    boardHeightLabel = new QLabel("Board Height");
    startLevelLabel = new QLabel("Start Level");
    targetLineLabel = new QLabel("Target Line");
    targetTimeLabel = new QLabel("Target Time");
    targetScoreLabel = new QLabel("Target Score");
    difficultyLabel = new QLabel("Difficulty");
}

void TetrisConfiguration::createLineEdits() {
    QString lineEditStyle = "QLineEdit { border: 2px solid #0f380f; border-radius: 5px; background-color: #9bbc0f; padding: 5px; }";

    boardWidthComboBox = new QComboBox();
    for (int w = 10; w <= 30; ++w) boardWidthComboBox->addItem(QString::number(w));
    boardWidthComboBox->setStyleSheet(lineEditStyle);
    boardHeightComboBox = new QComboBox();
    for (int h = 10; h <= 30; ++h) boardHeightComboBox->addItem(QString::number(h));
    boardHeightComboBox->setStyleSheet(lineEditStyle);
    boardHeightComboBox->setCurrentIndex(10);

    startLevelComboBox = new QComboBox();
    for (int lvl = 1; lvl <= Game::MAX_START_LEVEL ; lvl++) startLevelComboBox->addItem(QString::number(lvl));
    startLevelComboBox->setStyleSheet(lineEditStyle);

    targetLineLineEdit = new QLineEdit(QString::number(0));
    targetLineLineEdit->setStyleSheet(lineEditStyle);
    targetTimeLineEdit = new QLineEdit(QString::number(0));
    targetTimeLineEdit->setStyleSheet(lineEditStyle);
    targetScoreLineEdit = new QLineEdit(QString::number(0));
    targetScoreLineEdit->setStyleSheet(lineEditStyle);
    difficultyComboBox = new QComboBox();

    for (int diff = 1; diff <= 20; diff++) difficultyComboBox->addItem(QString::number(diff));
    difficultyComboBox->setStyleSheet(lineEditStyle);
}


int TetrisConfiguration::start(QApplication* myQtApp) {
    return myQtApp->exec();
}
