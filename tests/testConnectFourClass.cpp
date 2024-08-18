#include "ConnectFour.hpp"
#include <doctest.h>
#include <iostream>
#include <sstream>

TEST_CASE("Testando movimentos válidos e inválidos no ConnectFour") {
    ConnectFour connectFour(6, 7);

    SUBCASE("Movimento válido") {
      CHECK(connectFour.makeMove(1, "X")); 
      CHECK(connectFour.makeMove(7, "X"));  
    }

    SUBCASE("Movimento inválido - fora dos limites") {
      CHECK_FALSE(connectFour.makeMove(0, "X"));
      CHECK_FALSE(connectFour.makeMove(8, "X")); 
    }

    SUBCASE("Movimento inválido - coluna cheia") {
      CHECK(connectFour.makeMove(2, "X"));
      CHECK(connectFour.makeMove(2, "O"));
      CHECK(connectFour.makeMove(2, "X"));
      CHECK(connectFour.makeMove(2, "O"));
      CHECK(connectFour.makeMove(2, "X"));
      CHECK(connectFour.makeMove(2, "O"));
      CHECK_FALSE(connectFour.makeMove(2, "X")); 
    }
}

TEST_CASE("Testando a verificação de vitória na horizontal e vertical no ConnectFour") {
  ConnectFour connectFour(6, 7);

  SUBCASE("Vitória horizontal") {
    connectFour.makeMove(1, "X");
    connectFour.makeMove(2, "X");
    connectFour.makeMove(3, "X");
    connectFour.makeMove(4, "X");
    CHECK(connectFour.checkWin("X"));
  }

  SUBCASE("Vitória vertical") {
    connectFour.makeMove(5, "O");
    connectFour.makeMove(5, "O");
    connectFour.makeMove(5, "O");
    connectFour.makeMove(5, "O");
    CHECK(connectFour.checkWin("O"));
  }
}

TEST_CASE("Testando a verificação de vitória na diagonais no ConnectFour") {
    ConnectFour connectFour(6, 7);

    SUBCASE("Vitória diagonal (principal)") {
      connectFour.makeMove(1, "X");
      connectFour.makeMove(2, "O");
      connectFour.makeMove(2, "X");
      connectFour.makeMove(3, "O");
      connectFour.makeMove(3, "X");
      connectFour.makeMove(4, "O");
      connectFour.makeMove(3, "X");
      connectFour.makeMove(4, "O");
      connectFour.makeMove(5, "X");
      connectFour.makeMove(4, "O");
      connectFour.makeMove(4, "X");
      CHECK(connectFour.checkWin("X"));
    }

    ConnectFour connectFour2(6, 7);
    SUBCASE("Vitória diagonal (secundária)") {
      connectFour2.makeMove(5, "X");
      connectFour2.makeMove(4, "O");
      connectFour2.makeMove(4, "X");
      connectFour2.makeMove(3, "O");
      connectFour2.makeMove(3, "X");
      connectFour2.makeMove(2, "O");
      connectFour2.makeMove(3, "X");
      connectFour2.makeMove(2, "O");
      connectFour2.makeMove(1, "X");
      connectFour2.makeMove(2, "O");
      connectFour2.makeMove(2, "X");
      CHECK(connectFour2.checkWin("X"));
    }
}

TEST_CASE("Testando empate no ConnectFour") {
  ConnectFour connectFour(5, 6);
  std::string piece1 = "X";
  std::string piece2 = "O";

  // Preenche o tabuleiro alternando entre as peças, sem permitir uma vitória
  for (int col = 1; col <= 6; ++col) {
    for (int row = 1; row <= 5; ++row) {
      if (row % 2 == 0) {
        connectFour.makeMove(col, piece1);
      } else {
        connectFour.makeMove(col, piece2);
      }
    }

    if (col % 2 == 0) {
      std::string aux;

      aux = piece1;
      piece1 = piece2;
      piece2 = aux;
    }
  }

  CHECK(connectFour.isBoardFull());
  CHECK_FALSE(connectFour.checkWin("X"));
  CHECK_FALSE(connectFour.checkWin("O"));
}

TEST_CASE("Test countPossibleWins method") {
  std::string expectedOutput;

  std::ostringstream oss;
  std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

  SUBCASE("Test empty board") {
    ConnectFour connectFour(6, 7);

    connectFour.countPossibleWins("X");

    std::cout.rdbuf(oldCoutBuffer);
    
    expectedOutput = "\nPossíveis formas de ganhar para X: 0\n";
    CHECK(oss.str() == expectedOutput);
  }
  
  SUBCASE("Uma coluna com 3 peças alternadas") {
    ConnectFour connectFour(5, 6);

    connectFour.makeMove(1, "X"); 
    connectFour.makeMove(1, "O"); 
    connectFour.makeMove(1, "X"); 

    connectFour.countPossibleWins("X");
    expectedOutput = "\nPossíveis formas de ganhar para X: 3\n";
    CHECK(oss.str() == expectedOutput);

    oss.str("");
    oss.clear();

    connectFour.countPossibleWins("O");
    expectedOutput = "\nPossíveis formas de ganhar para O: 2\n";
    CHECK(oss.str() == expectedOutput);
  }

  SUBCASE("Uma coluna com 3 peças e 1 espaço vazio") {
    ConnectFour connectFour(6, 7);

    connectFour.makeMove(1, "X");
    connectFour.makeMove(1, "X");
    connectFour.makeMove(1, "X");

    connectFour.countPossibleWins("X");
    expectedOutput = "\nPossíveis formas de ganhar para X: 9\n";
    CHECK(oss.str() == expectedOutput);
  }

  SUBCASE("Uma diagonal com 3 peças e 1 espaço vazio") {
    ConnectFour connectFour(6, 7);

    connectFour.makeMove(1, "X");
    connectFour.makeMove(2, "O");
    connectFour.makeMove(2, "X");
    connectFour.makeMove(3, "O");
    connectFour.makeMove(3, "X");
    connectFour.makeMove(4, "O");
    connectFour.makeMove(3, "X");
    connectFour.makeMove(4, "O");
    connectFour.makeMove(5, "X");
    connectFour.makeMove(4, "O");

    connectFour.countPossibleWins("X");
    expectedOutput = "\nPossíveis formas de ganhar para X: 8\n";
    CHECK(oss.str() == expectedOutput);
  }

  SUBCASE("Test full board") {
    ConnectFour connectFour(5, 6);
    std::string piece1 = "O";
    std::string piece2 = "X";

    // Preenche o tabuleiro alternando entre as peças, sem permitir uma vitória
    for (int col = 1; col <= 6; ++col) {
      for (int row = 1; row <= 5; ++row) {
        if (row % 2 == 0) {
          connectFour.makeMove(col, piece1);
        } else {
          connectFour.makeMove(col, piece2);
        }
      }

      if (col % 2 == 0) {
        std::string aux;

        aux = piece1;
        piece1 = piece2;
        piece2 = aux;
      }
    }

    connectFour.countPossibleWins("X");
    expectedOutput = "\nPossíveis formas de ganhar para X: 0\n";
    CHECK(oss.str() == expectedOutput);

    oss.str("");
    oss.clear();

    connectFour.countPossibleWins("O");
    expectedOutput = "\nPossíveis formas de ganhar para O: 0\n";
    CHECK(oss.str() == expectedOutput);
  }

  std::cout.rdbuf(oldCoutBuffer);
}

/*TEST_CASE("Testando a função match no ConnectFour") {
  Player player1("Player1", "Name1");
  Player player2("Player2", "Name2");

  ConnectFour connectFour(6, 7);

  SUBCASE("Match termina sem erro") {
    CHECK_NOTHROW(connectFour.match(&player1, &player2));
  }
}*/