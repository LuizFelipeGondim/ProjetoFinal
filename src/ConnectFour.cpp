#include "ConnectFour.hpp"
#include <iostream>

ConnectFour::ConnectFour(int rows, int cols) : BoardGame(rows, cols) {}

bool ConnectFour::isValidMove(int col) const {
    if (col < 0 || col >= cols) return false;
    return board[0][col] == ' ';
}

bool ConnectFour::makeMove(int col, char player) {
    if (!isValidMove(col)) return false;

    for (int row = rows - 1; row >= 0; --row) {
        if (board[row][col] == ' ') {
            board[row][col] = player;
            return true;
        }
    }
    return false;
}

bool ConnectFour::checkWin(char player) const {
    return checkHorizontal(player) || checkVertical(player) || checkDiagonal(player);
}

bool ConnectFour::checkHorizontal(char player) const {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == player && board[row][col + 1] == player &&
                board[row][col + 2] == player && board[row][col + 3] == player) {
                return true;
            }
        }
    }
    return false;
}

bool ConnectFour::checkVertical(char player) const {
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row <= rows - 4; ++row) {
            if (board[row][col] == player && board[row + 1][col] == player &&
                board[row + 2][col] == player && board[row + 3][col] == player) {
                return true;
            }
        }
    }
    return false;
}

bool ConnectFour::checkDiagonal(char player) const {
    // Diagonais (bottom left to top right)
    for (int row = 0; row <= rows - 4; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == player && board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player && board[row + 3][col + 3] == player) {
                return true;
            }
        }
    }
    // Diagonais (top left to bottom right)
    for (int row = 3; row < rows; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == player && board[row - 1][col + 1] == player &&
                board[row - 2][col + 2] == player && board[row - 3][col + 3] == player) {
                return true;
            }
        }
    }
    return false;
}

int ConnectFour::countPossibleWins(char player) const {
    int count = 0;

    // Verificar horizontal
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == ' ' || board[row][col] == player) {
                if (board[row][col] == ' ' && 
                    ((col + 3 < cols && board[row][col + 1] == player && board[row][col + 2] == player && board[row][col + 3] == player) || 
                     (col + 2 < cols && board[row][col + 1] == player && board[row][col + 2] == player) || 
                     (col + 1 < cols && board[row][col + 1] == player))) {
                    ++count;
                }
            }
        }
    }

    // Verificar vertical
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row <= rows - 4; ++row) {
            if (board[row][col] == ' ' || board[row][col] == player) {
                if (board[row][col] == ' ' && 
                    ((row + 3 < rows && board[row + 1][col] == player && board[row + 2][col] == player && board[row + 3][col] == player) || 
                     (row + 2 < rows && board[row + 1][col] == player && board[row + 2][col] == player) || 
                     (row + 1 < rows && board[row + 1][col] == player))) {
                    ++count;
                }
            }
        }
    }

    // Verificar diagonais
    for (int row = 0; row <= rows - 4; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == ' ' || board[row][col] == player) {
                if (board[row][col] == ' ' && 
                    ((row + 3 < rows && col + 3 < cols && board[row + 1][col + 1] == player && board[row + 2][col + 2] == player && board[row + 3][col + 3] == player) || 
                     (row + 2 < rows && col + 2 < cols && board[row + 1][col + 1] == player && board[row + 2][col + 2] == player) || 
                     (row + 1 < rows && col + 1 < cols && board[row + 1][col + 1] == player))) {
                    ++count;
                }
            }
        }
    }

    for (int row = 3; row < rows; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == ' ' || board[row][col] == player) {
                if (board[row][col] == ' ' && 
                    ((row - 3 >= 0 && col + 3 < cols && board[row - 1][col + 1] == player && board[row - 2][col + 2] == player && board[row - 3][col + 3] == player) || 
                     (row - 2 >= 0 && col + 2 < cols && board[row - 1][col + 1] == player && board[row - 2][col + 2] == player) || 
                     (row - 1 >= 0 && col + 1 < cols && board[row - 1][col + 1] == player))) {
                    ++count;
                }
            }
        }
    }

    return count;
}

void ConnectFour::printBoard(char currentPlayer) const {
    std::cout << "Possíveis formas de ganhar para " << currentPlayer << ": " << countPossibleWins(currentPlayer) << '\n';

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
