/**
 * @file TicTacToeTests.cpp
 * @brief Testes para a classe TicTacToe utilizando a biblioteca doctest.
 */

#include <doctest.h>
#include "TicTacToe.hpp"
#include "Game.hpp"

/**
 * @brief Testa movimentos válidos e inválidos no jogo TicTacToe.
 */
TEST_CASE("Test valid and invalid moves in TicTacToe") {
  TicTacToe tictactoe(3, 3);

  /**
   * @brief Testa um movimento válido no jogo TicTacToe.
   */
  SUBCASE("Valid movement") {
    CHECK(tictactoe.makeMove(0, 0, "X")); 
  }

  /**
   * @brief Testa movimentos inválidos fora do tabuleiro.
   */
  SUBCASE("Invalid movement - out of board") {
    CHECK_FALSE(tictactoe.makeMove(-1, 0, "X")); 
    CHECK_FALSE(tictactoe.makeMove(0, 3, "O")); 
  }

  /**
   * @brief Testa movimentos inválidos em uma posição já ocupada.
   */
  SUBCASE("Invalid movement - position occupied") {
    tictactoe.makeMove(0, 0, "X");
    CHECK_FALSE(tictactoe.makeMove(0, 0, "O")); 
  }
}

/**
 * @brief Testa a verificação de empate no jogo TicTacToe.
 */
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

/**
 * @brief Testa a verificação de vitória no jogo TicTacToe.
 */
TEST_CASE("TicTacToe win check test") {
  TicTacToe tictactoe(3, 3);

  /**
   * @brief Testa a vitória por linha.
   */
  SUBCASE("Win by line") {
    tictactoe.makeMove(0, 0, "X");
    tictactoe.makeMove(0, 1, "X");
    tictactoe.makeMove(0, 2, "X");
    CHECK(tictactoe.checkWin());
  }

  /**
   * @brief Testa a vitória por coluna.
   */
  SUBCASE("Win by column") {
    tictactoe.makeMove(0, 0, "O");
    tictactoe.makeMove(1, 0, "O");
    tictactoe.makeMove(2, 0, "O");
    CHECK(tictactoe.checkWin());
  }

  /**
   * @brief Testa a vitória pela diagonal principal.
   */
  SUBCASE("Main diagonal victory") {
    tictactoe.makeMove(0, 0, "X");
    tictactoe.makeMove(1, 1, "X");
    tictactoe.makeMove(2, 2, "X");
    CHECK(tictactoe.checkWin());
  }

  /**
   * @brief Testa a vitória pela diagonal secundária.
   */
  SUBCASE("Victory by secondary diagonal") {
    tictactoe.makeMove(0, 2, "O");
    tictactoe.makeMove(1, 1, "O");
    tictactoe.makeMove(2, 0, "O");
    CHECK(tictactoe.checkWin());
  }

  /**
   * @brief Testa a ausência de vitória.
   */
  SUBCASE("No victory") {
    tictactoe.makeMove(0, 0, "X");
    tictactoe.makeMove(0, 1, "O");
    tictactoe.makeMove(0, 2, "X");
    CHECK_FALSE(tictactoe.checkWin());
  }
}
