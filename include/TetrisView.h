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

public:
    /**
     * Construct a TetrisView.
     * @param game The game controller.
     */
    TetrisView(std::shared_ptr<GameController> game);

    virtual ~TetrisView() = default;
    /**
     * Start the game.
     * @param myQtApp The Qt application.
     * @return The exit code.
     */
    int start(QApplication* myQtApp);

    /**
     * Update the view.
     */
    void update() override;

signals:
    void updateQt();
};

#endif //TETRIS_MYQTAPP_H
