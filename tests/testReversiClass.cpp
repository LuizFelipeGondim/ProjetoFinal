#include "doctest.h"
#include "Reversi.hpp"
#include "Player.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("Test the construction and initial state of the board") {
  Reversi game(8, 8);

  // Verifica se as posições iniciais estão corretas
  CHECK(game.getBoardContent(3, 3) == "X");
  CHECK(game.getBoardContent(3, 4) == "O");
  CHECK(game.getBoardContent(4, 3) == "O");
  CHECK(game.getBoardContent(4, 4) == "X");

  // Verifica se o restante do tabuleiro está vazio
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if ((i != 3 && i != 4) || (j != 3 && j != 4)) {
        CHECK(game.getBoardContent(i, j) == " ");
      }
    }
  }
}

TEST_CASE("Test thereIsNearby method") {
  Reversi game(8, 8);

  // Verifica posições próximas às iniciais
  CHECK(game.thereIsNearby(2, 3, "O") == true);
  CHECK(game.thereIsNearby(5, 4, "X") == true);

  // Verifica posições sem peças adjacentes
  CHECK(game.thereIsNearby(0, 0, "O") == false);
  CHECK(game.thereIsNearby(7, 7, "X") == false);
}

TEST_CASE("Test thereIsConnection method") {
  Reversi game(8, 8);

  // Testa uma jogada válida que criaria uma conexão
  CHECK(game.thereIsConnection(3, 5, "X", "O") == true);

  // Testa uma posição onde não há conexão
  CHECK(game.thereIsConnection(0, 0, "X", "O") == false);
}

TEST_CASE("Test makeMove method)") {
  Reversi game(8, 8);
  
  // Realiza uma jogada válida
  game.makeMove(3, 5, "X", "O");
  CHECK(game.getBoardContent(3, 5) == "X");
  CHECK(game.getBoardContent(3, 3) == "X");

  // Tenta realizar uma jogada em uma posição já ocupada
  CHECK_THROWS_AS(game.makeMove(3, 5, "O", "X"), std::invalid_argument);

  // Tenta realizar uma jogada em uma posição fora do tabuleiro
  CHECK_THROWS_AS(game.makeMove(8, 8, "O", "X"), std::out_of_range);
}

TEST_CASE("Test piecesCounter method") {
  std::string expectedOutput;

  std::ostringstream oss;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

  Reversi game(8, 8);

  game.makeMove(3, 5, "X", "O");
  game.piecesCounter();

  expectedOutput = 
    "\n"
    "-------------------------------------"
    "\n"
    "|      X = 4"
    "      |      O = 1      |"
    "\n"
    "-------------------------------------"
    "\n";
  
  CHECK(oss.str() == expectedOutput);
  std::cout.rdbuf(oldCoutBuffer);

}

TEST_CASE("Test isBoardFull method") {
  Reversi game(8, 8);
  
  // Simula o preenchimento do tabuleiro
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (game.getBoardContent(i, j) == " ") {
        game.makeMove(i, j, "X", "O");
      } 
    }
  }

  game.piecesCounter();
  CHECK(game.isBoardFull() == true);
}

TEST_CASE("Test isAnyPossiblePlay method") {
  Reversi game(8, 8);

  // Verifica jogadas possíveis após o estado inicial
  CHECK(game.isAnyPossiblePlay("X", "O") == true);

  // Simula um estado onde não há jogadas possíveis
  // Preenchendo o tabuleiro com X, exceto a última posição
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (!(i == 7 && j == 7) && game.getBoardContent(i, j) == " ") {
        game.makeMove(i, j, "X", "O");
      } 
    }
  }

  CHECK(game.isAnyPossiblePlay("X", "O") == false);
}
