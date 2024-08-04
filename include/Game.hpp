#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <vector>
#include <string>

class Game {
  protected:
    std::vector<std::vector<std::string>> _board;
    int _defaultRows; 
    int _defaultCols;

  public:
    Game(int rows, int cols);
    virtual ~Game() = default;

    virtual void printBoard(std::string currentPiece) const = 0;
    virtual bool isBoardFull() const = 0;
    virtual void match(Player* player1, Player* player2) = 0;
};

#endif
