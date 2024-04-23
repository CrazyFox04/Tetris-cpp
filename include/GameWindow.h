#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "observer/Subject.h"
#include "observer/Observer.h"

namespace Ui {
class GameWindow;
}

/**
 * @brief Is used to display the main window of the game.
 */
class GameWindow : public QMainWindow, public nvs::Observer
{
    Q_OBJECT

public:

    /**
     * @brief Constructs an instance of a GameWindow.
     *
     * @param game is the game to represent.
     * @param parent is the parent of this window.
     */
    explicit GameWindow(labyrinth::model::Game *game, QWidget *parent = 0);

    /**
     * @brief Updates this window content.
     *
     * @param subject is the subject.
     */
    void update(const nvs::Subject * subject) override;

    ~GameWindow();

public slots:

    /**
     * @brief Slot used to handle the rotation of the current maze card.
     */
    void rotateCurrentMazeCard();

    /**
     * @brief Slot used to pass the turn of the current player.
     */
    void passTurn();

    /**
     * @brief Slot used to handle a click on a pathway.
     */
    void handleClickedPathway();

private:

    /**
     * @brief Sets the board of the window up.
     */
    void setupBoard();

    /**
     * @brief Sets the data of the players up.
     */
    void setupPlayersData();

    /**
     * @brief Sets the current maze card up in the preview.
     */
    void setupCurrentMazecard();

    /**
     * @brief Set the objectives of game up. It displays a list of objectives
     * next to the board (with their id) and the ids are ddisplayed in the board.
     */
    void setupObjectives();

    /**
     * @brief Connects the pathways signal of the board to the
     * handleClickedPathway slot.
     */
    void setupConnection();

    Ui::GameWindow *ui;

    /**
     * @brief Is the game to represent.
     */
    labyrinth::model::Game *game_;

};

#endif // GAMEWINDOW_H
