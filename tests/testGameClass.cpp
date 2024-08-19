/**
 * @file testGameClass.cpp
 * @brief Testes para a classe Game utilizando a biblioteca doctest.
 */

#include "doctest.h"
#include "Game.hpp"
#include <sstream>
#include <iostream>

/** 
 * @brief Classe necessária pois Game é uma classe abstrata
 */

class TestGame : public Game {
  public:
    TestGame(int rows, int cols) : Game(rows, cols) {}

    std::string getBoardContent(int row, int col) const {
      return _board[row][col];
    }

    void setBoard(int row, int col, const std::string& value) {
      _board[row][col] = value;
    }

    void match(Player* p1, Player* p2) override {}
};


/**
 * @brief Testa o método construtor da classe Game.
 */
TEST_CASE("Test Game constructor") {
  TestGame game(3, 3); 

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      CHECK(game.getBoardContent(i, j) == " ");
    }
  }
}

/**
 * @brief Testa o método printBoard da classe Game.
 */
TEST_CASE("Test printBoard method") {
  TestGame game(3, 3);
  std::ostringstream out;
  std::streambuf* coutbuf = std::cout.rdbuf(); 
  std::cout.rdbuf(out.rdbuf());

  game.printBoard();

  std::cout.rdbuf(coutbuf);

  std::string expectedOutput = 
  "\n"
  "    "    
  "1   2   3  "
  "\n"
  "1 |   |   |   | "
  "\n"
  "2 |   |   |   | "
  "\n"
  "3 |   |   |   | "
  "\n";

  CHECK(out.str() == expectedOutput);
}


/**
 * @brief Testa o método isBoardFull da classe Game.
 */
TEST_CASE("Test isBoardFull method") {
  TestGame game(3, 3);

  CHECK(game.isBoardFull() == false);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      game.setBoard(i, j, "X");
    }
  }

  CHECK(game.isBoardFull() == true);
}
