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
    * @brief Configures the window properties and layout.
    */
    void configureWindow();


    void createLineEdits();

    /**
    * @brief Adds the fields to the form layout.
    */
    void addFields();

    /**
    * @brief Creates the buttons for the window.
    */
    void createButtons();

    /**
    * @brief Closes the widget and updates the game settings with the user input.
    */
    void closeWidget();

    /**
    * @brief Sets the initial values for the input fields based on the provided game settings.
    */
    void setValues();

public:
    /**
     * @brief Constructs a TetrisConfiguration widget.
     * @param settings A pointer to the GameSettings instance.
     */
    TetrisConfiguration(GameSettings* settings);

    /**
     * @brief Destructor for TetrisConfiguration.
     */
    virtual ~TetrisConfiguration() = default;

    /**
     * @brief Starts the application event loop and shows the configuration window.
     * @param myQtApp A pointer to the QApplication instance.
     * @return The result of the application event loop.
     */
    int start(QApplication* myQtApp);

protected:
    /**
     * @brief Handles the close event of the widget.
     * @param event The close event.
     */
    void closeEvent(QCloseEvent* event) override;

signals:

    /**
     * @brief Signal emitted when the user wants to exit the game.
     */
    void exitGame();
};
#endif //TETRISCONFIGURATION_H
