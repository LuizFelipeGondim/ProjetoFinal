#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <string>
#include "Game.hpp"

class Reversi : public Game{
    private:
        std::string _turn = "X";
        std::string _watching = "O";
        int _xCounter = 2;
        int _oCounter = 2;

    public:
        Reversi(int rows, int cols);
        bool thereIsNearby(int rows,int cols);
        bool thereIsConnection(int rows,int cols);
        void piecesCounter();
        void makeMove(int rows, int cols); //Antigo isPlaying
        bool isAnyPossiblePlay();

        bool isBoardFull() const override;
        void match(Player* player1, Player* player2) override;
};

#endif