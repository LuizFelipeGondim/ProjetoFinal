#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.hpp"
#include "ConnectFour.hpp"
#include "Reversi.hpp"
#include "TicTacToe.hpp"
#include <string>
#include <vector>

class GameBoard {
  private:
    std::vector<Player*> _players;
    void readPlayersFromFile();
    void writePlayersToFile();

  public:
    static const std::string FILENAME;

    GameBoard();
    ~GameBoard();

    bool searchPlayer(std::string nickName) const;
    void listStatistics(std::string orderType) const;

    void registerPlayer(std::string nickName, std::string name);
    void removePlayer(std::string nickName);
    void startGame(
      std::string game, 
      std::string nickNamePlayer1, 
      std::string nickNamePlayer2
    );
};

#endif