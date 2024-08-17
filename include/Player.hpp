#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <fstream>
#include <map>

class Player {
  private:
    std::string _nickName;
    std::string _name;
    std::map<std::string, int> _victories;
    std::map<std::string, int> _defeats;

  public:
    Player() = default;
    Player(std::string nickName, std::string name);

    ~Player();

    void showStatistics() const;
    void readPlayers(std::ifstream& in);
    void writePlayers(std::ofstream& out) const;

    std::string getName() const;
    std::string getNickName() const;

    void setVictories(std::string gameName);
    void setDefeats(std::string gameName);
};

#endif