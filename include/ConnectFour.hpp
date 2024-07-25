#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include "BoardGame.hpp"
#include <vector>

class ConnectFour : public BoardGame {
public:
    ConnectFour(int rows, int cols);
    bool isValidMove(int col) const override;
    bool makeMove(int col, char player) override;
    bool checkWin(char player) const override;
    int countPossibleWins(char player) const;  // Atualizado para aceitar jogador
    void printBoard(char currentPlayer) const;  // Atualizado para mostrar número de vitórias

private:
    bool checkHorizontal(char player) const;
    bool checkVertical(char player) const;
    bool checkDiagonal(char player) const;
};

#endif // CONNECTFOUR_HPP
