#ifndef NEXTTETROWIDGET_H
#define NEXTTETROWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

#include "GameController.h"

/**
 * @class NextTetroWidget
 * @brief Displays the next tetromino.
 *
 * This class is responsible for displaying the next tetromino.
 */
class NextTetroWidget : public QWidget {
    std::shared_ptr<GameController> game; //!< The game controller.

public:
    /**
     * Construct a NextTetroWidget.
     * @param game The game controller.
     * @param parent The parent widget.
     */
    NextTetroWidget(std::shared_ptr<GameController> game, QWidget *parent = nullptr);

    /**
     * Update the widget.
     */
    void update();
protected:
    /**
     *
     * @param event
     */
    void paintEvent(QPaintEvent *event) override;

private:
    /**
     * Get the color of the tetromino.
     * @param id The id of the tetromino.
     * @return The color.
     */
    QColor getColor(const Tetromino&tetromino);
};
#endif //NEXTTETROWIDGET_H
