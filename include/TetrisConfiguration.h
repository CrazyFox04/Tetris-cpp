//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISCONFIGURATION_H
#define TETRISCONFIGURATION_H
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QMainWindow>
#include <QCloseEvent>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QApplication>

#include "GameSettings.hpp"

/**
 * @class TetrisConfiguration
 * @brief The TetrisConfiguration class
 * The oppeing window of the game.
 * It invites the user to configure the game settings.
 * It allows the user to start the game.
 */
class TetrisConfiguration : public QWidget {
    Q_OBJECT
    bool wantToExit;
    QVBoxLayout* layout; //!< The main window.
    QFormLayout* formLayout; //!< The form layout.
    QLabel* titleLabel; //!< The title label.
    QLabel* boardWidthLabel; //!< The board width label.
    QLabel* boardHeightLabel; //!< The board height label.
    QLabel* startLevelLabel; //!< The start level label.
    QLabel* targetLineLabel; //!< The target line label.
    QLabel* targetTimeLabel; //!< The target time label.
    QLabel* targetScoreLabel; //!< The target score label.
    QLabel* difficultyLabel; //!< The difficulty label.
    QComboBox* boardWidthComboBox; //!< The board width combo box.
    QComboBox* boardHeightComboBox; //!< The board height combo box.
    QComboBox* startLevelComboBox; //!< The start level combo box.
    QComboBox* difficultyComboBox; //!< The difficulty combo box.
    QLineEdit* targetLineLineEdit; //!< The target line line edit.
    QLineEdit* targetTimeLineEdit; //!< The target time line edit.
    QLineEdit* targetScoreLineEdit; //!< The target score line edit.
    QPushButton* startButton; //!< The start button.

    GameSettings* settings; //!< The game settings.

    /**
     * Configure the window.
     */
    void configureWindow();

    /**
     * Create the necessary items.
     */
    void createLineEdits();

    /**
     * Add the fields to the form layout.
     */
    void addFields();

    /**
     * Create the necessary items.
     */
    void createButtons();

    /**
     * Register the settings and close the window.
     */
    void closeWidget();

    void setValues();

public:
    /**
     * Construct a TetrisConfiguration.
     * @param settings The game settings.
     */
    TetrisConfiguration(GameSettings* settings);

    virtual ~TetrisConfiguration() = default;

    /**
     * Launch the configuration window.
     * @param myQtApp The Qt application.
     * @return The exit code.
     */
    int start(QApplication* myQtApp);

protected:
    void closeEvent(QCloseEvent* event) override;

signals:
    void startTetrisView();
};
#endif //TETRISCONFIGURATION_H
