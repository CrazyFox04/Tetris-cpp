//
// Created by Enzo Renard on 26/04/2024.
//
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
    settings->difficulty = difficultyLineEdit->text().toInt();
    settings->boardWidth = boardWidthLineEdit->text().toInt();
    settings->boardHeight = boardHeightLineEdit->text().toInt();
    settings->startLevel = startLevelLineEdit->text().toInt();
    settings->targetLine = targetLineLineEdit->text().toInt();
    settings->targetTime = targetTimeLineEdit->text().toInt();
    settings->targetScore = targetScoreLineEdit->text().toInt();
    window.close();
}

void TetrisConfiguration::createButtons() {
    QPushButton* startButton = new QPushButton("Start");
    addRow(startButton);
    connect(startButton, &QPushButton::clicked, this, &TetrisConfiguration::close);
}

void TetrisConfiguration::addFields() {
    addRow(boardWidthLabel, boardWidthLineEdit);
    addRow(boardHeightLabel, boardHeightLineEdit);
    addRow(startLevelLabel, startLevelLineEdit);
    addRow(targetLineLabel, targetLineLineEdit);
    addRow(targetTimeLabel, targetTimeLineEdit);
    addRow(targetScoreLabel, targetScoreLineEdit);
    addRow(difficultyLabel, difficultyLineEdit);
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
    boardWidthLineEdit = new QLineEdit(QString::number(Board::DEFAULT_WIDTH));
    boardHeightLineEdit = new QLineEdit(QString::number(Board::DEFAULT_HEIGHT));
    startLevelLineEdit = new QLineEdit(QString::number(1));
    targetLineLineEdit = new QLineEdit(QString::number(0));
    targetTimeLineEdit = new QLineEdit(QString::number(0));
    targetScoreLineEdit = new QLineEdit(QString::number(0));
    difficultyLineEdit = new QLineEdit(QString::number(1));
}


int TetrisConfiguration::start(QApplication* myQtApp) {
    return myQtApp->exec();
}
