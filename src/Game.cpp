#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

Game::Game(int rows, int cols) : _defaultRows(rows), _defaultCols(cols){
    _board.resize(_defaultRows, std::vector<std::string>(_defaultCols, " "));
}
