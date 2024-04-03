#include "Bag.h"
#include <random>
#include <algorithm>
#include <stdexcept>

Bag *Bag::instance;

Bag::Bag() {
    possibleTetrominos.emplace_back(Tetromino{
            1, Position(0, 0), {Position(-2, 0), Position(0, 0), Position(-1, 0), Position(1, 0)}, true
    }); // I
    possibleTetrominos.emplace_back(Tetromino{
            2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)}, false
    }); // O
    possibleTetrominos.emplace_back(Tetromino{
            3, Position(0, 0), {Position(-1, 0), Position(0, 0), Position(1, 0), Position(0, 1)}, true
    }); // T
    possibleTetrominos.emplace_back(Tetromino{
            4, Position(0, 0), {Position(0, 0), Position(1, 0), Position(-1, 1), Position(0, 1)}, true
    }); // S
    possibleTetrominos.emplace_back(Tetromino{
            5, Position(0, 0), {Position(-1, 0), Position(0, 0), Position(0, 1), Position(1, 1)}, true
    }); // Z
    possibleTetrominos.emplace_back(Tetromino{
            6, Position(0, 0), {Position(-1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)}, true
    }); // J
    possibleTetrominos.emplace_back(Tetromino{
            7, Position(0, 0), {Position(1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)}, true
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
    for (auto &tetro: bag) {
        auto rotateTimes = rd() % 4;
        for (unsigned i = 0; i < rotateTimes; i++) {
            try {
                tetro.rotate(Rotation::CLOCKWISE);
            } catch (std::runtime_error &e) {
                // nop
            }
        }
    }
}

Tetromino Bag::getNext() {
    if (bag.empty()) {
        addTetrominosToBag();
        shuffle();
    }
    Tetromino next = Tetromino(bag.front());
    bag.erase(bag.begin());
    if (bag.empty()) {
        addTetrominosToBag();
        shuffle();
    }
    return next;
}

const Tetromino &Bag::peekNext() const {
    if (bag.empty()) {
        throw std::runtime_error("Bag is empty");
    }
    return bag.front();
}

int Bag::size() {
    return static_cast<int>(bag.size());
}

void Bag::addTetrominosToBag() {
    for (const auto &tetromino: possibleTetrominos) {
        bag.emplace_back(tetromino);
    }
}

int Bag::getNumberOfTetrominos() const {
    return static_cast<int>(possibleTetrominos.size());
}

std::vector<Tetromino> Bag::getAvailableTetrominos() const {
    std::vector<Tetromino> constTetrominos;
    constTetrominos.reserve(possibleTetrominos.size());
    for (const auto &tetromino: possibleTetrominos) {
        constTetrominos.emplace_back(tetromino);
    }
    return constTetrominos;
}