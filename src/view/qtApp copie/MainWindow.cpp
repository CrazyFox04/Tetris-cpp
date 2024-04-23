#include "MainWindow.h"
#include "GameController.h"
#include "Direction.h"
#include "Game.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
        setupUI();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Q:
            controller->moveActiveTetromino(Direction::LEFT);
            break;
        case Qt::Key_D:
            controller->moveActiveTetromino(Direction::RIGHT);
            break;
        case Qt::Key_S:
            controller->moveActiveTetromino(Direction::DOWN);
            break;
        case Qt::Key_A:
            controller->rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_E:
            controller->rotateActiveTetromino(Rotation::CLOCKWISE);
            break;
        case Qt::Key_Z:
            controller->dropActiveTetromino();
            break;
    }
}

void MainWindow::setupUI() {
    gameBoardWidget = new GameBoardWidget(this);
    infoPanelWidget = new InfoPanelWidget(this);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(gameBoardWidget);
    layout->addWidget(infoPanelWidget);

    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    delete gameBoardWidget;
    delete infoPanelWidget;
}
