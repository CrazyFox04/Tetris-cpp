#ifndef TETRIS_DEV4_PROJET_BAG_H
#define TETRIS_DEV4_PROJET_BAG_H

#include <vector>
#include "Tetromino.h"

/**
 * Tetromino bag used in a Tetris game.
 * Keep a single instance of the bag and provide the next Tetromino to be used.
 * It cannot be empty, so it will be refilled when it is empty.
 */
class Bag {
    static Bag* instance; //!< Singleton instance of the bag
    std::vector<Tetromino> possibleTetrominos; //!< All possible Tetrominos that can be in the bag
    std::vector<Tetromino> bag; //!< Tetrominos that are in the bag

    /**
     * Add all possible tetrominos to the bag.
     */
    void addTetrominosToBag();

    /**
     * Add legacies tetrominos to the bag and add it to the possible tetrominos.
     */
    Bag();

    /**
     * Shuffle the bag.
     */
    void shuffle();

public:
    /**
     * \brief Remove copy constructor.
     *
     * The copy constructor is removed to ensure that only one instance of the bag exists.
     */
    Bag(const Bag&) = delete;

    /**
    * \briefRemove copy assignment operator.
    *
    * The copy assignment operator is removed to ensure that only one instance of the bag exists.
    */
    Bag& operator=(const Bag&) = delete;

    /**
     * Get the number of possible tetrominos.
     * @return number of possible tetrominos
     */
    int getNumberOfTetrominos() const;

    /**
     * Get the singleton instance of the bag.
     * @return singleton instance of the bag
     */
    static Bag& getInstance();

    /**
     * \brief Get the next Tetromino in the bag and remove it.
     *
     * When the bag is empty, it will be refilled and shuffled.
     * @return next Tetromino in the bag
     */
    Tetromino getNext();

    /**
     * Get the next Tetromino in the bag without removing it.
     * @throw std::runtime_error if bag is empty
     * @return const reference to the next Tetromino in the bag
     */
    const Tetromino& peekNext() const;

    /**
     * Get the number of Tetrominos in the bag.
     * @return number of Tetrominos in the bag
     */
    int size();

    /**
     * Get all possible Tetrominos that can be in the bag.
     * @return copy of all possible Tetrominos that can be in the bag
     */
    std::vector<Tetromino> getAvailableTetrominos() const;
};


#endif //TETRIS_DEV4_PROJET_BAG_H
