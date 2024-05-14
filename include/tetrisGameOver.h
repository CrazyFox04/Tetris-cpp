#ifndef TETRISGAMEOVER_H
#define TETRISGAMEOVER_H
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "GameController.h"

/**
 * @class TetrisGameOver
 * @brief The TetrisGameOver class
 * This class displays the game over window,
 * displaying the end game information.
 * It allows the user to restart or quit the game.
 */
class TetrisGameOver : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> game; //!< The game controller.
    QVBoxLayout* layout; //!< The layout.
    QLabel* gameOverLabel; //!< The game over label.
    QLabel* detailsLabel; //!< The details label.
    QHBoxLayout* buttonLayout; //!< The button layout.
    QPushButton* restartButton; //!< The restart button.
    QPushButton* quitButton; //!< The quit button.

    /**
     * Configure the window.
     */
    void configureWindow();

    /**
     * Create the necessary items.
     */
    void createItems();

    /**
     * Update the items.
     */
    void updateItems();

public:
    /**
     * Construct a TetrisGameOver.
     * @param game The game controller.
     * @param parent The parent widget.
     */
    TetrisGameOver(std::shared_ptr<GameController> game);

    /**
     * Destruct a TetrisGameOver.
     */
    virtual ~TetrisGameOver() = default;

    /**
     * Start the game over window.
     * @param myQtApp The Qt application.
     * @return The exit code.
     */
    int start(QApplication* myQtApp);

    /**
     * Manage the restart Button
     */
    void restartGame();

    /**
     * Manage the quit Button
     */
    void quitGame();

signals:
    void exitGame();
};
#endif //TETRISGAMEOVER_H
