#include "TetrisConfiguration.h"
#include "Game.h"
#include "TetrisView.h"

#include <QCloseEvent>
#include <QList>


TetrisConfiguration::TetrisConfiguration(GameSettings *settings)
        :  wantToExit(true), settings(settings), layout(new QVBoxLayout(this)), formLayout(new QFormLayout()),
          titleLabel(new QLabel("TETRIS", this)),
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
          targetLineLineEdit(new QLineEdit(QString::number(0), this)),
          targetTimeLineEdit(new QLineEdit(QString::number(0), this)),
          targetScoreLineEdit(new QLineEdit(QString::number(0), this)),
          startButton(new QPushButton("Start", this)) {
    setWindowTitle("Tetris Configuration");
    configureWindow();
    setLayout(layout);
}

void TetrisConfiguration::configureWindow() {
    resize(400, 300);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(24);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("QLabel { color : #2F3E46; }");

    createLineEdits();
    addFields();
    createButtons();
    setValues();

    layout->addWidget(titleLabel);
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addLayout(formLayout);
    layout->addWidget(startButton);
    layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    layout->setAlignment(titleLabel, Qt::AlignCenter);
    layout->setAlignment(formLayout, Qt::AlignCenter);
    layout->setAlignment(startButton, Qt::AlignCenter);

    setStyleSheet("background-color: #84A98C;");
    layout->setContentsMargins(10, 10, 10, 10);
}

void TetrisConfiguration::setValues() {
    boardWidthComboBox->setCurrentText(QString::number(settings->boardWidth));
    boardHeightComboBox->setCurrentText(QString::number(settings->boardHeight));
    startLevelComboBox->setCurrentText(QString::number(settings->startLevel));
    difficultyComboBox->setCurrentText(QString::number(settings->difficulty));
    targetLineLineEdit->setText(QString::number(settings->targetLine));
    targetTimeLineEdit->setText(QString::number(settings->targetTime));
    targetScoreLineEdit->setText(QString::number(settings->targetScore));
}

void TetrisConfiguration::closeWidget() {
    settings->difficulty = difficultyComboBox->currentText().toInt();
    settings->boardWidth = boardWidthComboBox->currentText().toInt();
    settings->boardHeight = boardHeightComboBox->currentText().toInt();
    settings->startLevel = startLevelComboBox->currentText().toInt();
    settings->targetLine = targetLineLineEdit->text().toInt();
    settings->targetTime = targetTimeLineEdit->text().toInt();
    settings->targetScore = targetScoreLineEdit->text().toInt();
    wantToExit = false;
    close();
    deleteLater();
}

void TetrisConfiguration::createButtons() {
    QString buttonStyle =
            "QPushButton { border-radius: 5px; background-color: #354F52; padding: 5px; color: #CAD2C5; }";
    startButton->setStyleSheet(buttonStyle);
    startButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    startButton->setMinimumWidth(300);
    connect(startButton, &QPushButton::clicked, this, &TetrisConfiguration::closeWidget);
}

void TetrisConfiguration::addFields() {
    formLayout->addRow(boardWidthLabel, boardWidthComboBox);
    formLayout->addRow(boardHeightLabel, boardHeightComboBox);
    formLayout->addRow(startLevelLabel, startLevelComboBox);
    formLayout->addRow(difficultyLabel, difficultyComboBox);
    formLayout->addRow(targetLineLabel, targetLineLineEdit);
    formLayout->addRow(targetTimeLabel, targetTimeLineEdit);
    formLayout->addRow(targetScoreLabel, targetScoreLineEdit);

    QList<QLabel *> labels = {boardWidthLabel, boardHeightLabel, startLevelLabel,
                              targetLineLabel, targetTimeLabel, targetScoreLabel, difficultyLabel};
    for (auto label: labels) {
        label->setStyleSheet("QLabel { color : #354F52; }");

    }

    QList<QWidget *> widgets = {boardWidthComboBox, boardHeightComboBox, startLevelComboBox,
                                targetLineLineEdit, targetTimeLineEdit, targetScoreLineEdit, difficultyComboBox};
    for (auto widget: widgets) {
        widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        widget->setMinimumWidth(200);
    }
}

void TetrisConfiguration::createLineEdits() {
    QString lineEditStyle =
            "QLineEdit { border-radius: 5px; background-color: #354F52; padding: 5px; color: #CAD2C5; }";
    QString comboBoxStyle =
            "QComboBox { border-radius: 5px; background-color: #354F52; padding: 5px; color: #CAD2C5; }";

    for (int w = 10; w <= 30; ++w) boardWidthComboBox->addItem(QString::number(w));
    boardWidthComboBox->setStyleSheet(comboBoxStyle);
    boardWidthComboBox->setEditable(true);
    for (int h = 10; h <= 30; ++h) boardHeightComboBox->addItem(QString::number(h));
    boardHeightComboBox->setStyleSheet(comboBoxStyle);
    boardHeightComboBox->setCurrentIndex(10);
    boardHeightComboBox->setEditable(true);
    for (int lvl = 1; lvl <= 20; lvl++) startLevelComboBox->addItem(QString::number(lvl));
    startLevelComboBox->setStyleSheet(comboBoxStyle);
    startLevelComboBox->setEditable(true);
    for (int diff = 1; diff <= 20; diff++) difficultyComboBox->addItem(QString::number(diff));
    difficultyComboBox->setStyleSheet(comboBoxStyle);
    difficultyComboBox->setEditable(true);

    targetLineLineEdit->setStyleSheet(lineEditStyle);
    targetTimeLineEdit->setStyleSheet(lineEditStyle);
    targetScoreLineEdit->setStyleSheet(lineEditStyle);


    // Align the text to the center
    QList<QComboBox *> comboBoxes = {boardHeightComboBox, boardWidthComboBox, startLevelComboBox, difficultyComboBox};
    for (auto comboBox: comboBoxes) {
        comboBox->lineEdit()->setAlignment(Qt::AlignCenter);
        comboBox->lineEdit()->setReadOnly(true); // Make the line edit read-only
    }

    QList<QLineEdit *> lineEdits = {targetLineLineEdit, targetTimeLineEdit, targetScoreLineEdit};
    for (auto lineEdit: lineEdits) {
        lineEdit->setAlignment(Qt::AlignCenter);
    }
}

int TetrisConfiguration::start(QApplication *myQtApp) {
    show();
    return myQtApp->exec();
}

void TetrisConfiguration::closeEvent(QCloseEvent* event) {
    if (wantToExit) {
        emit exitGame();
        deleteLater();
    } else {
        QWidget::closeEvent(event);
    }
}

#include "moc_TetrisConfiguration.cpp"
