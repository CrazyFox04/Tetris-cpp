#ifndef TETRIS_INFOBOX_H
#define TETRIS_INFOBOX_H

#include "GameController.h"
#include <QString>
#include <QLabel>
#include <QTimer>
#include <QHBoxLayout>

/**
 * @class InfoBox
 * @brief Displays the score, lines, and level.
 *
 * This class is responsible for displaying the score, lines, and level.
 */
class InfoBox : public QWidget {
    Q_OBJECT
    QLabel* score; //!< The score label.
    QLabel* lines; //!< The lines label.
    QLabel* level; //!< The level label.
    QLabel levelUpLabel; //!< The level up label.
    QTimer levelUpTimer; //!< The level up timer.
    QWidget* nextTetroWidget; //!< The next tetromino widget.
    std::shared_ptr<GameController> game; //!< The game controller.
    int currentLevel; //!< The current level.

    /**
     * Set up the info widget.
     * @param layout The layout to add the widget to.
     * @param labelText The text of the label.
     * @param valueLabel The value label.
     */
    void setupInfoWidget(QLayout* layout, const QString&labelText, QLabel* valueLabel);

public:
    /**
     * Construct an InfoBox.
     * @param game The game controller.
     * @param parent The parent widget.
     */
    InfoBox(std::shared_ptr<GameController> game, QWidget* parent = nullptr);

public slots:
    /**
     * Update the info box.
     */
    void updateQt();
};

#endif //TETRIS_INFOBOX_H
