#include "ConnectFour.hpp"
#include <iostream>

ConnectFour::ConnectFour(int rows, int cols) : Game(rows, cols) {}

bool ConnectFour::isValidMove(int col) const {
    if (col < 1 || col > cols) return false;
    return board[0][col - 1] == ' ';
}

bool ConnectFour::makeMove(int col, char player) {
    if (!isValidMove(col)) return false;
    col -= 1; // Ajustar para índice de base 0
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
    for (int row = 0; row <= rows - 4; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            if (board[row][col] == player && board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player && board[row + 3][col + 3] == player) {
                return true;
            }
        }
    }
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

void ConnectFour::printBoard(char currentPlayer) const {
    std::cout << "Possíveis formas de ganhar para " << currentPlayer << ": " << countPossibleWins(currentPlayer) << '\n';

    std::cout << "  ";
    for (int col = 1; col <= cols; ++col) {
        if(col > 1){
          std::cout << " " << col << "  ";
        }
        else{
            std::cout << col << "  ";
        }
       
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

int ConnectFour::countPossibleWins(char player) const {
    int count = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            int emptyCount = 0;
            int playerCount = 0;

            for (int i = 0; i < 4; ++i) {
                if (board[row][col + i] == player) {
                    playerCount++;
                } else if (board[row][col + i] == ' ') {
                    emptyCount++;
                }
            }

            if (playerCount + emptyCount >= 4 && playerCount > 0) {
                count++;
            }
        }
    }

    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row <= rows - 4; ++row) {
            int emptyCount = 0;
            int playerCount = 0;

            for (int i = 0; i < 4; ++i) {
                if (board[row + i][col] == player) {
                    playerCount++;
                } else if (board[row + i][col] == ' ') {
                    emptyCount++;
                }
            }

            if (playerCount + emptyCount >= 4 && playerCount > 0) {
                count++;
            }
        }
    }

    for (int row = 0; row <= rows - 4; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            int emptyCount = 0;
            int playerCount = 0;

            for (int i = 0; i < 4; ++i) {
                if (board[row + i][col + i] == player) {
                    playerCount++;
                } else if (board[row + i][col + i] == ' ') {
                    emptyCount++;
                }
            }

            if (playerCount + emptyCount >= 4 && playerCount > 0) {
                count++;
            }
        }
    }

    for (int row = 3; row < rows; ++row) {
        for (int col = 0; col <= cols - 4; ++col) {
            int emptyCount = 0;
            int playerCount = 0;

            for (int i = 0; i < 4; ++i) {
                if (board[row - i][col + i] == player) {
                    playerCount++;
                } else if (board[row - i][col + i] == ' ') {
                    emptyCount++;
                }
            }

            if (playerCount + emptyCount >= 4 && playerCount > 0) {
                count++;
            }
        }
    }

    return count;
}
