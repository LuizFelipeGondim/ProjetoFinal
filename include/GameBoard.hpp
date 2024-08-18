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


  public:
    GameBoard();
    ~GameBoard();

    static const std::string FILENAME;
    static std::string transformToLowerCase(std::string word);

    bool searchPlayer(std::string nickName) const;
    void listStatistics(std::string orderType) const;
    size_t getNumberOfPlayers() const;

    void removePlayer(std::string nickName);
    void startGame(
      std::string game, 
      std::string nickNamePlayer1, 
      std::string nickNamePlayer2
    );
    void readPlayersFromFile();
    void writePlayersToFile();
    std::string getPlayerNickName();

    void registerPlayer(std::string nickName, std::string name);

    void clearPlayers();
};

#endif