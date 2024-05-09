#ifndef TETRIS_GAMEBOARDWIDGET_H
#define TETRIS_GAMEBOARDWIDGET_H

#include <QWidget>
#include <memory>
#include "GameController.h"
#include <QPainter>

/**
 * @class GameBoardWidget
 * @brief The GameBoardWidget class
 * This class displays the game board on the screen.
 */
class GameBoardWidget : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> controller; ///< The game controller.

public:
    /**
     * Destruct a GameBoardWidget.
     * @param parent The parent widget.
     */
    ~GameBoardWidget() = default;

    /**
     * Construct a GameBoardWidget.
     * @param parent The parent widget.
     */
    GameBoardWidget(QWidget *parent = nullptr);

protected:
    /**
     * Draw the game board.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent *event) override;
};

#endif //TETRIS_GAMEBOARDWIDGET_H
