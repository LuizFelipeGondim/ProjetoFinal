#include "BoardGame.hpp"
#include <iostream>
#include <algorithm>

BoardGame::BoardGame(int rows, int cols) : rows(rows), cols(cols) {
    board.resize(rows, std::vector<char>(cols, ' '));
}

BoardGame::~BoardGame() {}

void BoardGame::printBoard() const {
    // Imprime os números das colunas
    std::cout << "  ";
    for (int col = 0; col < cols; ++col) {
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

bool BoardGame::isBoardFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

void BoardGame::resetBoard() {
    for (auto& row : board) {
        std::fill(row.begin(), row.end(), ' ');
    }
}
