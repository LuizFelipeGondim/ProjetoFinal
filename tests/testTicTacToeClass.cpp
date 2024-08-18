#include <doctest.h>
#include "TicTacToe.hpp"
#include "Game.hpp"

TEST_CASE("Test valid and invalid moves in TicTacToe") {
  TicTacToe tictactoe(3, 3);

  SUBCASE("Valid movement") {
    CHECK(tictactoe.makeMove(0, 0, "X")); 
  }

  SUBCASE("Invalid movement - out of board") {
    CHECK_FALSE(tictactoe.makeMove(-1, 0, "X")); 
    CHECK_FALSE(tictactoe.makeMove(0, 3, "O")); 
  }

  SUBCASE("Invalid movement - position occupied") {
    tictactoe.makeMove(0, 0, "X");
    CHECK_FALSE(tictactoe.makeMove(0, 0, "O")); 
  }
}

TEST_CASE("TicTacToe tie check test") {
  TicTacToe tictactoe(3, 3);

  // Preenche o tabuleiro com movimentos que resultam em empate
  tictactoe.makeMove(0, 0, "X");
  tictactoe.makeMove(0, 1, "O");
  tictactoe.makeMove(0, 2, "X");
  tictactoe.makeMove(1, 0, "O");
  tictactoe.makeMove(1, 1, "X");
  tictactoe.makeMove(1, 2, "O");
  tictactoe.makeMove(2, 0, "O");
  tictactoe.makeMove(2, 1, "X");
  tictactoe.makeMove(2, 2, "O");

  CHECK_FALSE(tictactoe.checkWin());
}

TEST_CASE("TicTacToe win check test") {
  TicTacToe tictactoe(3, 3);

  SUBCASE("Win by line") {
    tictactoe.makeMove(0, 0, "X");
    tictactoe.makeMove(0, 1, "X");
    tictactoe.makeMove(0, 2, "X");
    CHECK(tictactoe.checkWin());
  }

  SUBCASE("Win by column") {
    tictactoe.makeMove(0, 0, "O");
    tictactoe.makeMove(1, 0, "O");
    tictactoe.makeMove(2, 0, "O");
    CHECK(tictactoe.checkWin());
  }

  SUBCASE("Main diagonal victory") {
    tictactoe.makeMove(0, 0, "X");
    tictactoe.makeMove(1, 1, "X");
    tictactoe.makeMove(2, 2, "X");
    CHECK(tictactoe.checkWin());
  }

  SUBCASE("Victory by secondary diagonal") {
    tictactoe.makeMove(0, 2, "O");
    tictactoe.makeMove(1, 1, "O");
    tictactoe.makeMove(2, 0, "O");
    CHECK(tictactoe.checkWin());
  }

  SUBCASE("No victory") {
    tictactoe.makeMove(0, 0, "X");
    tictactoe.makeMove(0, 1, "O");
    tictactoe.makeMove(0, 2, "X");
    CHECK_FALSE(tictactoe.checkWin());
  }
}