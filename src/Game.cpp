#include "Game.hpp"
#include <iostream>
#include <algorithm>

Game::Game(int rows, int cols) : rows(rows), cols(cols) {
    board.resize(rows, std::vector<char>(cols, ' '));
}

Game::~Game() {}

void Game::printBoard() const {
    std::cout << "  ";
    for (int col = 1; col <= cols; ++col) {
        std::cout << " " << col << "  ";
    }
    std::cout << "\n";

    for (const auto& row : board) {
        std::cout << "| ";
        for (char cell : row) {
            std::cout << cell << " | ";
        }
        std::cout << "\n";
    }
    std::cout << std::string(cols * 4 + 2, '-') << '\n';
}

bool Game::isBoardFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void Game::resetBoard() {
    for (auto& row : board) {
        std::fill(row.begin(), row.end(), ' ');
    }
}
