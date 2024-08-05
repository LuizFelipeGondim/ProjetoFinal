#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include "Game.hpp"
#include "Player.hpp"
#include <vector>
#include <string>

class ConnectFour : public Game {
  private:
    std::string _currentPiece;

    bool checkHorizontal() const;
    bool checkVertical() const;
    bool checkDiagonal() const;
    bool isValidMove(int col) const;
    bool checkWin() const;
    bool makeMove(int col);

  public:
    ConnectFour(int rows, int cols);

    bool isBoardFull() const override;
    void printBoard() const override;  // Atualizado para mostrar número de vitórias
    int countPossibleWins() const;  // Atualizado para aceitar jogador

    void match(Player* player1, Player* player2) override;
};

#endif
