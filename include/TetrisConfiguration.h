//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISCONFIGURATION_H
#define TETRISCONFIGURATION_H
#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QMainWindow>
#include <QCloseEvent>
#include <QLineEdit>

#include "GameSettings.hpp"

class TetrisConfiguration : public QFormLayout {
    QWidget window;
    QLabel* boardWidthLabel;
    QLabel* boardHeightLabel;
    QLabel* startLevelLabel;
    QLabel* targetLineLabel;
    QLabel* targetTimeLabel;
    QLabel* targetScoreLabel;
    QLabel* difficultyLabel;
    QLineEdit* boardWidthLineEdit;
    QLineEdit* boardHeightLineEdit;
    QLineEdit* startLevelLineEdit;
    QLineEdit* targetLineLineEdit;
    QLineEdit* targetTimeLineEdit;
    QLineEdit* targetScoreLineEdit;
    QLineEdit* difficultyLineEdit;

    GameSettings* settings;

    void configureWindow();

    void createLabels();

    void createLineEdits();

    void addFields();

    void createButtons();

    void close();
public:
    TetrisConfiguration(GameSettings* settings);

    int start(QApplication* myQtApp);
};
#endif //TETRISCONFIGURATION_H
