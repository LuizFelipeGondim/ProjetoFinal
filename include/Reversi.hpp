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
        void counter();
        void isPlaying(int rows,int cols);
        bool isAnyPossiblePlay();
        bool gameOver();

        bool isBoardFull() const override;
        void printBoard() const override;
        void match() override;
};

#endif