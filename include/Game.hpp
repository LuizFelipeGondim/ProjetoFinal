#ifndef BOARDGAME_HPP
#define BOARDGAME_HPP

#include <vector>
#include <string>

class BoardGame {
protected:
    std::vector<std::vector<char>> board;
    int rows, cols;

public:
    BoardGame(int rows, int cols);
    virtual ~BoardGame();

    virtual void printBoard() const;
    virtual bool isValidMove(int col) const = 0;
    virtual bool makeMove(int col, char player) = 0;
    virtual bool checkWin(char player) const = 0;
    virtual bool isBoardFull() const;
    virtual void resetBoard();
};

#endif // BOARDGAME_HPP
