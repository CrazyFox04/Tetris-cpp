#include "Bag.h"
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

Bag *Bag::instance;

Bag::Bag() {
    possibleTetrominos.reserve(7);
    possibleTetrominos.emplace_back(Tetromino{
            1, Position(0, 0),
            {Position(-2, 0), Position(0, 0), Position(-1, 0), Position(1, 0)}
    }); // I
    possibleTetrominos.emplace_back(Tetromino{
            2, Position(0, 0),
            {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)}, false
    }); // O
    possibleTetrominos.emplace_back(Tetromino{
            3, Position(0, 0),
            {Position(-1, 0), Position(0, 0), Position(1, 0), Position(0, 1)}
    }); // T
    possibleTetrominos.emplace_back(Tetromino{
            4, Position(0, 0),
            {Position(0, 0), Position(1, 0), Position(-1, 1), Position(0, 1)}
    }); // S
    possibleTetrominos.emplace_back(Tetromino{
            5, Position(0, 0),
            {Position(-1, 0), Position(0, 0), Position(0, 1), Position(1, 1)}
    }); // Z
    possibleTetrominos.emplace_back(Tetromino{
            6, Position(0, 0),
            {Position(-1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)}
    }); // J
    possibleTetrominos.emplace_back(Tetromino{
            7, Position(0, 0),
            {Position(1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)}
    }); // L

    addTetrominosToBag();
    shuffle();
}

Bag &Bag::getInstance() {
    if (instance == nullptr) {
        instance = new Bag();
    }
    return *instance;
}

void Bag::shuffle() {
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::ranges::shuffle(bag, g);
    std::for_each(bag.begin(), bag.end(), [](Tetromino &tetro) {
        if (tetro.canRotate()) {
            for (unsigned i = 0; i < (rd() % 4); ++i) {
                tetro.rotate(Rotation::CLOCKWISE);
            }
        }
    });
}

Tetromino Bag::getNext() {
    if (bag.size() <= 1) {
        if (bag.size() == 1) {
            Tetromino next = Tetromino(bag.front());
            addTetrominosToBag();
            shuffle();
            bag.insert(bag.begin(), next);
        } else {
            addTetrominosToBag();
            shuffle();
        }
    }
    Tetromino next = Tetromino(bag.front());
    bag.erase(bag.begin());
    return next;
}

const Tetromino &Bag::peekNext() const {
    if (bag.empty()) {
        throw std::runtime_error("Bag is empty");
    }
    return bag.front();
}

int Bag::size() const {
    return static_cast<int>(bag.size());
}

void Bag::addTetrominosToBag() {
    std::copy(possibleTetrominos.begin(), possibleTetrominos.end(), std::back_inserter(bag));
}

int Bag::getNumberOfTetrominos() const {
    return static_cast<int>(possibleTetrominos.size());
}

const std::vector<Tetromino> Bag::getAvailableTetrominos() const {
    std::vector<Tetromino> availableTetrominos;
    std::copy(possibleTetrominos.begin(), possibleTetrominos.end(), std::back_inserter(availableTetrominos));
    const std::vector<Tetromino> constTetrominos = availableTetrominos;
    return constTetrominos;
}