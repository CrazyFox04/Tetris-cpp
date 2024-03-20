//
// Created by Julien Delcombel on 07/03/2024.
//
#include "Bag.h"
#include <random>
#include <algorithm>
Bag* Bag::instance;

Bag::Bag() {
    possibleTetrominos.push_front(
        Tetromino(1, Position(0, 1), {Position(-2, 0), Position(-1, 0), Position(0, 0), Position(1, 0)})); // I
    possibleTetrominos.push_front(
        Tetromino(2, Position(0, 0), {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)})); // O
    possibleTetrominos.push_front(
        Tetromino(3, Position(0, 0), {Position(-1, 0), Position(0, 0), Position(1, 0), Position(0, 1)})); // T
    possibleTetrominos.push_front(
        Tetromino(4, Position(0, 0), {Position(0, 0), Position(1, 0), Position(-1, 1), Position(0, 1)})); // S
    possibleTetrominos.push_front(
        Tetromino(5, Position(0, 0), {Position(-1, 0), Position(0, 0), Position(0, 1), Position(1, 1)})); // Z
    possibleTetrominos.push_front(
        Tetromino(6, Position(0, 0), {Position(-1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)})); // J
    possibleTetrominos.push_front(
        Tetromino(7, Position(0, 0), {Position(1, -1), Position(-1, 0), Position(0, 0), Position(1, 0)})); // L

    //TODO: Ajouter les tétriminos customs dans possibleTetrominos

    // Copier les tétriminos possibles dans le sac
    for (const auto&tetromino: possibleTetrominos) {
        bag.push_back(tetromino);
    }
    shuffle();
}

Bag& Bag::getInstance() {
    // if instance is null create it
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
        shuffle();
    }
    Tetromino& next = bag.front();
    bag.erase(bag.begin());
    return next;
}

int Bag::size() {
    return bag.size();
}
