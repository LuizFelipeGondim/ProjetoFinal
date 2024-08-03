#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.hpp"
#include <string>
#include <vector>

class GameBoard {
  private:
    std::vector<Player*> _players;
    //Reversi _reversi;
    //Lig4 _lig4;

  public:
    static const std::string FILENAME;

    GameBoard();
    ~GameBoard();

    bool searchPlayer(std::string nickName) const;
    void listStatistics(std::string orderType) const;

    void registerPlayer(std::string nickName, std::string name);
    void removePlayer(std::string nickName);

    void readPlayersFromFile();
    void writePlayersToFile();
};

#endif