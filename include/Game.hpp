#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

class Game {
protected:
    std::vector<std::vector<std::string>> _board;
    int _defaultRows; 
    int _defaultCols;

public:
    Game(int rows, int cols);
    virtual ~Game() = default;

    virtual void printBoard(std::string currentPiece) const = 0;
    virtual bool isBoardFull() const = 0;
    virtual void match() = 0;
};

#endif
