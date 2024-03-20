//
// Created by Julien Delcombel on 07/03/2024.
//
#include "Bag.h"
#include <random>
#include <algorithm>
Bag* Bag::instance;

Bag::Bag() {
    possibleTetrominos.emplace_back(Tetromino{
        1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)}
    }); // I
    possibleTetrominos.emplace_back(Tetromino{
        2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)}
    }); // O
    possibleTetrominos.emplace_back(Tetromino{
        3, Position(0, 0), {Position(-1, 0), Position(0, 0), Position(1, 0), Position(0, 1)}
    }); // T
    possibleTetrominos.emplace_back(Tetromino{
        4, Position(0, 0), {Position(0, 0), Position(1, 0), Position(-1, 1), Position(0, 1)}
    }); // S
    possibleTetrominos.emplace_back(Tetromino{
        5, Position(0, 0), {Position(-1, 0), Position(0, 0), Position(0, 1), Position(1, 1)}
    }); // Z
    possibleTetrominos.emplace_back(Tetromino{
        6, Position(0, 0), {Position(-1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)}
    }); // J
    possibleTetrominos.emplace_back(Tetromino{
        7, Position(0, 0), {Position(1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)}
    }); // L

    //TODO: Ajouter les tétrominos customs dans possibleTetrominos

    // Copier les tétriminos possibles dans le sac
    addTetrominosToBag();
    shuffle();
}

Bag& Bag::getInstance() {
    if (instance == nullptr) {
        instance = new Bag();
    }
    return *instance;
}

void Bag::shuffle() {
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::ranges::shuffle(bag, g);
}

Tetromino& Bag::getNext() {
    if (bag.size() <= 0) {
        addTetrominosToBag();
        shuffle();
    }
    Tetromino&next = bag.front();
    bag.erase(bag.begin());
    return next;
}

int Bag::size() {
    return bag.size();
}

void Bag::addTetrominosToBag() {
    for (const auto&tetromino: possibleTetrominos) {
        bag.emplace_back(tetromino);
    }
}

int Bag::getNumberOfTetrominos() const {
    return possibleTetrominos.size();
}
