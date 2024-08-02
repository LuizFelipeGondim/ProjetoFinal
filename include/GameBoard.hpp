#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <string>
#include <vector>

class GameBoard {
    private:
        //std::vector<Player*> _players;
        //Reversi _reversi;
        //Lig4 _lig4;

    public:
        ~GameBoard();

        void registerPlayer(std::string name, std::string nickname);
        void listStatistics(char orderType);

        bool searchPlayer(std::string nickname);
};

#endif