#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <string>

class ConnectFour : public Game {
  public:
    ConnectFour(int rows, int cols);

    bool isValidMove(int col) const;
    bool makeMove(int col, std::string piece);
    bool isBoardFull() const override;
    bool checkWin(std::string piece) const;
    void printBoard(std::string currentPiece) const override;  // Atualizado para mostrar número de vitórias
    int countPossibleWins(std::string piece) const;  // Atualizado para aceitar jogador

    void match(Player* player1, Player* player2) override;

  private:
    bool checkHorizontal(std::string piece) const;
    bool checkVertical(std::string piece) const;
    bool checkDiagonal(std::string piece) const;
};

#endif
