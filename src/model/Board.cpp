#include "Board.h"
#include "Bag.h"
#include <random>
#include <algorithm>
#include <stdexcept>

Board::Board() : Board(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_DIFFICULTY) {
}

Board::Board(const int w, const int h, const int difficulty)
        : width(w), height(h), occupied(h, std::vector<bool>(w, false)) {
    refPosition = Position(width / 2 - 1, 0);
    if (isBoardTooSmallForAvailableTetromino()) {
        throw std::invalid_argument("Board is too small for the available tetrominos");
    }
    initialize(difficulty);
}

bool Board::isBoardTooSmallForAvailableTetromino() const {
    for (const auto& available_tetromino: Bag::getInstance().getAvailableTetrominos()) {
        if (available_tetromino.get_height() >= height / 2.0 || available_tetromino.get_length() >= width / 2.0) {
            return true;
        }
    }
    return false;
}

void Board::initialize(int difficulty) {
    if (difficulty < 1) difficulty = 1;
    if (difficulty > 20) difficulty = 20;

    double fillPercentage = (difficulty - 1) * (70.0 / 19.0);
    int linesToFill = static_cast<int>((fillPercentage / 100) * height);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(fillPercentage / 100);

    for (int i = height - linesToFill; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            occupied[i][j] = d(gen);
        }
    }
}

void Board::addTetromino(Tetromino tetromino) {
    positionTetroOnTop(tetromino);
    if (isOutside(tetromino) || isOccupied(tetromino)) {
        throw std::out_of_range("The tetromino can't be placed because there isn't enough space on the board for it.");
    }
    setOccupiedForTetromino(tetromino);
    tetrominos.push_back(tetromino);
}

void Board::positionTetroOnTop(Tetromino &tetromino) {
    int dy = 0;
    while (isOutside(tetromino)) {
        tetromino.move(Direction::DOWN.first, Direction::DOWN.second);
        dy++;
        if (dy >= height) {
            throw std::invalid_argument("Board is too small to add the tetromino");
        }
    }
}

bool Board::isOccupied(Tetromino &tetromino) const {
    for (const auto &cell: tetromino.get_relative_cells()) {
        if (isOccupied(refPosition.get_y() + cell.get_y(),
                       refPosition.get_x() + cell.get_x())) {
            return true;
        }
    }
    return false;
}

void Board::setOccupiedForTetromino(Tetromino &tetromino) {
    if (isOccupied(tetromino)) {
        throw std::invalid_argument("The position of the tetromino is already occupied");
    }
    if (isOutside(tetromino)) {
        throw std::out_of_range("The position of the tetromino is outside the board");
    }
    for (const auto &pos: tetromino.get_relative_cells()) {
        occupied[refPosition.get_y() + pos.get_y()][refPosition.get_x() + pos.get_x()] = true;
    }
}

bool Board::isOutside(const Tetromino &tetromino) const {
    for (auto &relative_cell: tetromino.get_relative_cells()) {
        if (isOutside(relative_cell.get_y() + refPosition.get_y(), relative_cell.get_x() + refPosition.get_x())) {
            return true;
        }
    }
    return false;
}

void Board::setOccupiedForActiveTetromino() {
    for (const auto &cell: tetrominos.back().get_relative_cells()) {
        int absX = refPosition.get_x() + cell.get_x();
        int absY = refPosition.get_y() + cell.get_y();
        occupied[absY][absX] = true;
    }
}

void Board::moveActiveTetromino(Direction2D direction) {
    Tetromino &activeTetromino = tetrominos.back();
    clearOccupiedForActiveTetromino();
    if (isOutside(Tetromino(activeTetromino).move(direction.first, direction.second))) {
        setOccupiedForActiveTetromino();
        throw std::out_of_range("The new position is outside the board");
    }
    if (isOccupied(Tetromino(activeTetromino).move(direction.first, direction.second))) {
        setOccupiedForActiveTetromino();
        throw std::invalid_argument("The new position is already occupied");
    }
    activeTetromino.move(direction.first, direction.second);
    setOccupiedForActiveTetromino();
}

void Board::rotateActiveTetromino(Rotation rotation) {
    Tetromino &activeTetromino = tetrominos.back();
    clearOccupiedForActiveTetromino();
    if (isOutside(Tetromino(activeTetromino).rotate(rotation))) {
       throw std::out_of_range("The new position is outside the board");
    }
    if (isOccupied(Tetromino(activeTetromino).rotate(rotation))) {
        throw std::invalid_argument("The new position is already occupied");
    }
    activeTetromino.rotate(rotation);
    setOccupiedForActiveTetromino();
}

bool Board::isOutside(const int row, const int column) const {
    return row < 0 || row >= height || column < 0 || column >= width;
}

bool Board::activeTetroIsBellow(int row) const {
    const Tetromino &activeTetromino = tetrominos.back();
    for (const auto &cell: activeTetromino.get_relative_cells()) {
        if (cell.get_y() + refPosition.get_y() > row) {
            return true;
        }
    }
    return false;
}

bool Board::isOccupied(const int row, const int column) const {
    if (row < 0 || row >= height || column < 0 || column >= width) {
        return true;
    }
    return occupied[row][column];
}

int Board::removeCompleteLines() {
    int linesRemoved = 0;
    for (int y = 0; y < height; ++y) {
        if (isLineComplete(y)) {
            clearLine(y);
            moveLinesDown(y);
            linesRemoved++;
        }
    }
    return linesRemoved;
}

bool Board::isLineComplete(const int line) const {
    for (int j = 0; j < width; j++) {
        if (!occupied[line][j]) {
            return false;
        }
    }
    return true;
}

void Board::clearLine(int line) {
    for (int j = 0; j < width; j++) {
        occupied[line][j] = false;
    }
    std::for_each(tetrominos.begin(), tetrominos.end(), [line](Tetromino &tetro) {
        auto cells = tetro.get_relative_cells();
        erase_if(cells,[line](const Position &pos) {
            return pos.get_y() == line;
        });
        tetro.set_relative_cells(cells);
    });
}

void Board::moveLinesDown(const int clearedline) {
    for (int y = clearedline; y > 0; --y) {
        for (int x = 0; x < width; ++x) {
            occupied[y][x] = occupied[y - 1][x];
        }
    }
    std::for_each(tetrominos.begin(), tetrominos.end(), [clearedline, this](Tetromino &tetro) {
        auto modifiedCells = std::vector<Position>();
        auto cells = tetro.get_relative_cells();
        std::for_each(cells.begin(), cells.end(), [clearedline, &modifiedCells, this](const Position &cell) {
            if (cell.get_y() + this->refPosition.get_y() < clearedline) {
                modifiedCells.emplace_back(cell.get_x(), cell.get_y() + 1);
            } else {
                modifiedCells.emplace_back(cell.get_x(), cell.get_y());
            }
        });
        tetro.set_relative_cells(modifiedCells);
    });
}

const Tetromino &Board::getActiveTetromino() const {
    return tetrominos.back();
}

const std::vector<Tetromino> Board::getTetrominos() const {
    return tetrominos;
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

const std::vector<std::vector<bool>> Board::getOccupied() const {
   return occupied;
}

Position Board::getRefPosition() const {
    return refPosition;
}

void Board::clearOccupiedForActiveTetromino() {
    auto &activeTetromino = tetrominos.back();
    auto cells = activeTetromino.get_relative_cells();
    std::for_each(cells.begin(), cells.end(), [this](Position &cell) {
        occupied[refPosition.get_y() + cell.get_y()][refPosition.get_x() + cell.get_x()] = false;
    });
}

void Board::clear() {
    tetrominos.clear();
    for (auto &row: occupied) {
        std::fill(row.begin(), row.end(), false);
    }
    initialize(1);
}

bool Board::activeTetrominoIsRotatable() const {
    const Tetromino &activeTetromino = tetrominos.back();
    return activeTetromino.canRotate();
}

Tetromino Board::getDroppedTetro() const {
    Tetromino activeTetromino = tetrominos.back();
    int dropDistance = 0;
    for (int i = 0; i < activeTetromino.get_height(); ++i) {
       activeTetromino.move(Direction::DOWN.first, Direction::DOWN.second);
        ++dropDistance;
    }
    if (isOutside(activeTetromino) || isOccupied(activeTetromino)) {
        return tetrominos.back();
    }
    while (!isOccupied(activeTetromino) && !isOutside(activeTetromino)) {
        activeTetromino.move(Direction::DOWN.first, Direction::DOWN.second);
    }
    activeTetromino.move(0, -1);
    return activeTetromino;
}