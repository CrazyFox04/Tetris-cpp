#include "InfoPanelWidget.h"

InfoPanelWidget::InfoPanelWidget(QWidget* parent) : QWidget(parent) {
        setupUI();
    }

void InfoPanelWidget::setupUI() {
    scoreLabel = new QLabel("Score: 0", this);
    levelLabel = new QLabel("Level: 1", this);
    linesLabel = new QLabel("Lines: 0", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(scoreLabel);
    layout->addWidget(levelLabel);
    layout->addWidget(linesLabel);

    setLayout(layout);
}
