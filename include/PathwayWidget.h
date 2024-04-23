#ifndef PATHWAYWIDGET_H
#define PATHWAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include "Game.h"

namespace Ui {
class PathwayWidget;
}

/**
 * @brief Is used to represent a maze card. It can be used in the board or in
 * the preview for the current maze card.
 */
class PathwayWidget : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Constructs an instance of a PathwayWidget with the specified game
     * and board position.
     *
     * If the given position coordinates are not given, they are set to a
     * negative value and this widget should be used as a simple preview for
     * a pathway, not a board component.
     *
     * @param game is the game to represent a pathway for.
     * @param row is the maze row of the pathway to represent.
     * @param column is the maze column of the pathway to represent.
     * @param parent is the parent of this widget.
     */
    explicit PathwayWidget(labyrinth::model::Game *game,
                           int row = -1,
                           int column = -1,
                           QWidget *parent = 0);

    /**
     * @brief Gets the pathway represented by this widget.
     *
     * @return the pathway represented by this widget.
     */
    labyrinth::model::MazeCard getPathway() const;

    /**
     * @brief Gets this widget row in its parent (which should be a QGridLayout).
     *
     * @return this widget row in its parent.
     */
    unsigned getRow() const { return row_; }

    /**
     * @brief Gets this widget column in its parent (which should be a QGridLayout).
     *
     * @return this widget column in its parent.
     */
    unsigned getColumn() const { return column_; }

    /**
     * @brief Tells if this widget is used as a preview.
     *
     * @return true if this widget is used as a preview.
     */
    bool isPreviewPathWayWidget() const { return row_ < 0 && column_ < 0; }

    ~PathwayWidget();

signals:

    /**
     * @brief The signal is emitted when a user clicks this widget with the left
     * button of his mouse.
     */
    void clicked();

protected:

    /**
     * @brief Emits a clicked signal when this widget is clicked with the mouse
     * left button.
     *
     * @param event is the event to handle.
     */
    void mousePressEvent(QMouseEvent *event) override;

private:

    /**
     * @brief If some players are located on the represented pathway, they are
     * shown on this pathwaay corner by a square of their color.
     */
    void setupPlayers();

    /**
     * @brief Draws the representation of this widget pathway. A wall is brown,
     * a path is green.
     */
    void setupPathways();

    /**
     * @brief If an objective is located on this
     */
    void setupObjectives();

    Ui::PathwayWidget *ui;

    /**
     * @brief Is the game to represent a pathway for.
     */
    labyrinth::model::Game *game_;

    /**
     * @brief Is this widget row in its parent. This row matches the one of the
     * represented pathway in the game.
     */
    int row_;

    /**
     * @brief Is this widget column in its parent. This column matches the one
     * of the represented pathway in the game.
     */
    int column_;

};

#endif // PATHWAYWIDGET_H
