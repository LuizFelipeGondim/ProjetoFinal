#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
using namespace std;

class Game{
    protected:
        vector<vector<string>> _board;
        int _defaultRows;
        int _defaultCols;

    public:
        Game(int rows, int cols);
        virtual ~Game(){}
        void printBoard();
        virtual void match() = 0;
};

#endif