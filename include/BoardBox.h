#ifndef TETRIS_BOARDBOX_H
#define TETRIS_BOARDBOX_H
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "GameController.h"
#include "TetroView.h"
#include <memory>
#include <qgridlayout.h>
#include <QStackedLayout>
#include <QList>
/**
 * @class BoardBox
 * @brief Displays the game board.
 *
 * This class is responsible for drawing the game board.
 */
class BoardBox : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> game; ///< The game controller.
    QList<TetroView*> tetroViews; ///< The tetrominos to display.
    TetroView* dropVisualizationTetro; ///< The active tetro if dropped.
    QGridLayout* layout; ///< The layout of the board.

public:
    /**
     * Construct a BoardBox.
     * @param game The game controller.
     * @param parent The parent widget.
     */
    explicit BoardBox(std::shared_ptr<GameController> game, QWidget* parent = nullptr);
    QColor activeTetrominoColor() const;
    void setActiveTetrominoColor(const QColor &color);
    void restart();

public slots:
    void updateQt();

protected:
    /**
     * Draw the game board.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * Handle key press events.
     * @param event The key event.
     */
    void keyPressEvent(QKeyEvent* event) override;

private:
    /**
     * Draw the borders of the board.
     * @param painter The painter to use.
     */
    void drawBorders(QPainter&painter);
};

#endif //TETRIS_BOARDBOX_H
