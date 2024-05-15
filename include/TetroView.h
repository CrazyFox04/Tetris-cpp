//
// Created by Enzo Renard on 10/05/2024.
//

#ifndef TETROVIEW_H
#define TETROVIEW_H
#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QKeyEvent>

#include "GameController.h"
#include "Tetromino.h"

class TetroView : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QColor color READ getCurrentColor WRITE setColor)
    Tetromino tetromino; //!< The tetromino.
    std::shared_ptr<GameController> game; //!< The game controller.
    QColor color; //!< The color.
    bool isGhost; //!< The ghost flag.
    bool hasBlinked; //!< The blink flag.

    /**
     * @brief Gets the gradient for drawing the tetromino blocks.
     * @param x The x-coordinate of the block.
     * @param y The y-coordinate of the block.
     * @return The linear gradient for the block.
     */
    QLinearGradient getGradient(int x, int y) const;
public:
    /**
     * @brief Constructs a TetroView.
     * @param game The game controller.
     * @param tetromino The tetromino to display.
     * @param isGhost Indicates if this tetromino is a ghost (transparent).
     * @param parent The parent widget.
     */
    TetroView(std::shared_ptr<GameController> game, Tetromino tetromino, bool isGhost, QWidget* parent = nullptr);

    /**
     * @brief Handles the paint event for the widget.
     * @param event The paint event.
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * @brief Updates the displayed tetromino.
     * @param tetromino The new tetromino to display.
     */
    void updateQt(Tetromino tetromino);

    /**
     * @brief Sets the color of the tetromino.
     * @param color The new color.
     */
    void setColor(QColor color);

    /**
     * @brief Sets the color based on the tetromino type.
     */
    void getColorFromTetro();

    /**
     * @brief Makes the tetromino blink.
     * @param blinkTime The duration of the blink animation in milliseconds.
     */
    void makeItBlink(int blinkTime);

    /**
     * @brief Gets the current color of the tetromino.
     * @return The current color.
     */
    QColor getCurrentColor() const;
};

/**
 * @brief Gets the color associated with a tetromino type.
 * @param tetromino The tetromino.
 * @return The color associated with the tetromino type.
 */
QColor getColor(Tetromino& tetromino);

#endif //TETROVIEW_H
