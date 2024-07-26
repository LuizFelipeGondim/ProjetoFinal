#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <string>
#include "Game.hpp"
using namespace std;

class Reversi : public Game{
    private:
        string _turn = "X";
        string _watching = "O";
        int _xCounter = 2;
        int _oCounter = 2;

    public:
        Reversi(int rows, int cols);
        bool thereIsNearby(int rows,int cols);
        bool thereIsConnection(int rows,int cols);
        void counter();
        void isPlaying(int rows,int cols);
        bool piecesLeft();
        bool isAnyPossiblePlay();
        bool gameOver();
        void match() override;
};

#endif