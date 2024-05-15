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
    QList<TetroView *> tetroViews; ///< The tetrominos to display.
    TetroView *blockView; ///< The view for occupied blocks.
    TetroView *dropVisualizationTetro; ///< The view for drop visualization.
    QGridLayout *layout; ///< The layout for the board.

public:
    /**
    * @brief Constructs a BoardBox widget.
    *
    * This constructor initializes the BoardBox with a game controller and parent widget. It sets up
    * the visual representation of the game board and connects the update signal for updating the widget.
    *
    * @param game A shared pointer to the GameController instance.
    * @param parent A pointer to the parent QWidget.
    */
    explicit BoardBox(std::shared_ptr<GameController> game, QWidget* parent = nullptr);

    void restart();

public slots:

    /**
    * @brief Slot for updating the widget.
    *
    * This method is called to update the widget, including the blocks, tetrominos, and animations.
    * It checks for changes in the number of tetrominos and restarts if necessary.
    */
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

    /**
     * @brief Initializes the painting of occupied blocks on the board.
     *
     * This method retrieves the occupied positions from the game board and creates a TetroView
     * to represent the occupied blocks.
     */
    void initPaintOccupied();

    /**
     * @brief Updates the visual representation of the occupied blocks.
     *
     * This method retrieves the occupied positions from the game board and updates the corresponding TetroView.
     */
    void updateBlocks();

    /**
     * @brief Updates the visual representation of the tetrominos.
     *
     * This method updates the TetroViews for the tetrominos in the game board. It adds new TetroViews
     * for newly added tetrominos.
     */
    void updateTetros();

    /**
     * @brief Animates the previously dropped tetromino.
     *
     * This method makes the previously dropped tetromino blink as a visual indicator.
     */
    void animatePreviousTetro();

    /**
     * @brief Updates the drop visualization tetromino.
     *
     * This method updates the visual representation of where the active tetromino will land when dropped.
     */
    void updateTetroVisualization();
};

#endif //TETRIS_BOARDBOX_H
