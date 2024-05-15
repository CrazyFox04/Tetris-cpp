#ifndef TETRIS_MYQTAPP_H
#define TETRIS_MYQTAPP_H
#include "BoardBox.h"
#include "InfoBox.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QApplication>
#include "Observer.h"
#include "GameController.h"
#include "GameSettings.hpp"

/**
 * @class TetrisView
 * @brief Displays the game.
 *
 * This class is responsible for displaying all components of the game.
 * It is the main view of the game.
 */
class TetrisView : public QWidget, public Observer {
    Q_OBJECT
    QHBoxLayout* mainLayout; //!< The main layout.
    InfoBox* myInfoBox; //!< The info box.
    BoardBox* myBoardBox; //!< The board box.
    std::shared_ptr<GameController> game; //!< The game controller.

    /**
     * @brief Handles the end of the game.
     *
     * This method is called when the game ends, either because the player has won or the game is over.
     * It closes the view, removes itself as an observer from the game, and schedules itself for deletion.
     */
    void endOfGame();
public:
    /**
     * Construct a TetrisView.
     * @param game The game controller.
     */
    TetrisView(std::shared_ptr<GameController> game);

    /**
     * @brief Destructor for TetrisView.
     */
    virtual ~TetrisView() = default;

    /**
     * Start the game.
     * @param myQtApp The Qt application.
     * @return The exit code.
     */
    int start(QApplication* myQtApp);

    /**
     * @brief Updates the view.
     *
     * This method is called to update the view, typically in response to changes in the game state.
     */
    void update() override;

protected:
    /**
     * @brief Handles the close event of the widget.
     * @param event The close event.
     */
    void closeEvent(QCloseEvent* event) override;

signals:
    /**
     * @brief Signal emitted to update the Qt view.
     */
    void updateQt();
};

#endif //TETRIS_MYQTAPP_H
