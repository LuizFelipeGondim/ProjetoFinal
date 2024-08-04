#include "Game.hpp"
#include <iostream>
#include <algorithm>

Game::Game(int rows, int cols) : _defaultRows(rows), _defaultCols(cols) {
    _board.resize(_defaultRows, std::vector<std::string>(_defaultCols, " "));
}