#ifndef TETRIS_MAINWINDOW_H
#define TETRIS_MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QHBoxLayout>

#include "GameController.h"
#include "InfoPanelWidget.h"
#include "GameBoardWidget.h"

class MainWindow : public QMainWindow {
Q_OBJECT

    std::shared_ptr<GameController> controller;
    GameBoardWidget *gameBoardWidget{};
    InfoPanelWidget *infoPanelWidget{};

    void setupUI();

public:
    ~MainWindow();

    MainWindow(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif //TETRIS_MAINWINDOW_H
