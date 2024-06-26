#ifndef TETRIS_DEV4_PROJET_TETROMINO_H
#define TETRIS_DEV4_PROJET_TETROMINO_H

#include <vector>

#include "Position.h"

/**
 * @class Tetromino
 * @brief Represents a Tetris piece with a unique identifier and a collection of cells.
 *
 * A Tetromino is a geometric shape composed of square blocks arranged in a specific layout.
 * It includes functionalities to rotate and move the shape in a Tetris game.
 */
class Tetromino {
    int id; //!< The unique identifier of the Tetromino.
    Position refPosition; //!< Reference position of the Tetromino.
    std::vector<Position> cells; //!< Vector of cells that make up the Tetromino.
    bool canRotate_; //!< Flag to indicate if the Tetromino is rotatable.

public:
    /**
     * Constructor for Tetromino.
     * @param id Unique identifier for the Tetromino.
     * @param center Reference position for the Tetromino.
     * @param cells Initial cell positions relative to the reference position.
     */
    Tetromino(int id, Position center, std::vector<Position> cells, bool canRotate = true);

    /**
     * Getter for the unique identifier of the Tetromino.
     * @return the unique identifier.
     */
    int get_id() const;

    /**
     * Getter for the reference position of the Tetromino.
     * @return the reference position.
     */
    Position get_ref_position() const;

    /**
     * Getter for the relative cell positions of the Tetromino.
     * @return the relative cell positions.
     */
    std::vector<Position> get_relative_cells() const;

    /**
     * Moves the Tetromino by a specified offset.
     * @param dx The horizontal offset.
     * @param dy The vertical offset.
     */
    Tetromino& move(int dx, int dy);

    /**
     * Sets the relative cell positions of the Tetromino.
     * @param newCells The new relative cell positions.
     */
    void set_relative_cells(const std::vector<Position>&newCells);

    /**
     * Getter for the length of the Tetromino.
     * Calculates the length of the Tetromino.
     * @return the length of the Tetromino.
     */
    int get_length() const;

    /**
     * Getter for the height of the Tetromino.
     * Calculates the height of the Tetromino.
     * @return the height of the Tetromino.
     */
    int get_height() const;

    /**
     * Get the rotatibility of the Tetromino.
     * @return true if the Tetromino is rotatable, false otherwise.
     */
    bool canRotate() const;

    /**
 * Rotates the Tetromino in the specified direction.
 * The rotation is performed around the reference position of the Tetromino.
 * @param rotation The direction of the rotation. It can be either CLOCKWISE or COUNTERCLOCKWISE.
 * @throws runtime_error if the Tetromino is not rotatable.
     * @see Rotation
 */
    Tetromino& rotate(Rotation rotation);
};

/**
 * Compares two Tetrominos for equality based on their properties.
 * @param Tetromino1 The first Tetromino.
 * @param Tetromino2 The second Tetromino.
 * @return true if the Tetrominos are equal, false otherwise.
 */
bool operator==(const Tetromino&Tetromino1, const Tetromino&Tetromino2);

#endif //TETRIS_DEV4_PROJET_TETROMINO_H
