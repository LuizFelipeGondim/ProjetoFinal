#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>

class Game {
protected:
    std::vector<std::vector<char>> board;
    int rows, cols;

public:
    Game(int rows, int cols);
    virtual ~Game();

    virtual void printBoard() const;
    virtual bool isValidMove(int col) const = 0;
    virtual bool makeMove(int col, char player) = 0;
    virtual bool checkWin(char player) const = 0;
    virtual bool isBoardFull() const;
    virtual void resetBoard();
};

#endif // GAME_HPP
