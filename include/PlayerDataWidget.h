#ifndef PLAYERDATAWIDGET_H
#define PLAYERDATAWIDGET_H

#include <QWidget>

namespace Ui {
class PlayerDataWidget;
}

/**
 * @brief This widget is used to represent a player and its data. It shows the
 * color of the player, its current objective and the number of objectives
 * remaining.
 */
class PlayerDataWidget : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Constructs an instance of PlayerDataWidget.
     *
     * @param player is the player to represent.
     * @param isCurrentPlayer tells if the given player is the current one.
     * @param parent is the parent of this widget.
     */
    explicit PlayerDataWidget(bool isCurrentPlayer = false, QWidget *parent = 0);

    ~PlayerDataWidget();

private:

    /**
     * @brief Sets the player data up.
     */
    void setupPlayerData(bool);

    /**
     * @brief Sets the current objective of this player.
     */
    void setCurrentObjective();

    /**
     * @brief Sets the background color of this widget to the color of the
     * represented player.
     */
    void setupBackgroundColor();

    Ui::PlayerDataWidget *ui;

    /**
     * @brief Is the player to represent.
     */
    labyrinth::model::Player player_;

};

#endif // PLAYERDATAWIDGET_H
