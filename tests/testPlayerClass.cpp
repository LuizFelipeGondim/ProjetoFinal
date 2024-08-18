#include "doctest.h"

#include "Player.hpp"
#include "GameBoard.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

TEST_CASE("Testing Player class") {
  Player player("fulano1", "John");

  SUBCASE("Test constructor") {
    CHECK(player.getNickName() == "fulano1");
    CHECK(player.getName() == "John");
  }

  SUBCASE("Test initial statistics") {

    std::ostringstream oss;
    //Substitui buffer de saída do cout pelo de oss
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

    player.showStatistics();

    //Restauracao do buffer de saida do cout
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = 
      "\n"
      "fulano1 John\n"
      "REVERSI   - V: 0 D: 0\n"
      "LIG4      - V: 0 D: 0\n"
      "TICTACTOE - V: 0 D: 0\n";

    CHECK(oss.str() == expectedOutput);
  }

  SUBCASE("Test setVictories and setDefeats") {
    player.setVictories("reversi");
    player.setVictories("connectFour");
    player.setVictories("ticTacToe");
    player.setDefeats("reversi");
    player.setDefeats("connectFour");
    player.setDefeats("connectFour");
    player.setDefeats("ticTacToe");

    std::ostringstream oss;
    //Substitui buffer de saída do cout pelo de oss
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

    player.showStatistics();

    //Restauracao do buffer de saida do cout
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = 
      "\n"
      "fulano1 John\n"
      "REVERSI   - V: 1 D: 1\n"
      "LIG4      - V: 1 D: 2\n"
      "TICTACTOE - V: 1 D: 1\n";
    
    CHECK(oss.str() == expectedOutput);
  }

  SUBCASE("Test readPlayers and writePlayers") {
    // Cria um arquivo temporário para teste
    std::ofstream outFile("testPlayerData.txt");
    player.writePlayers(outFile);
    outFile.close();

    // Lê os dados
    Player newPlayer("", "");
    std::ifstream inFile("testPlayerData.txt");
    newPlayer.readPlayers(inFile);
    inFile.close();

    CHECK(newPlayer.getNickName() == "fulano1");
    CHECK(newPlayer.getName() == "John");
    CHECK(newPlayer.getVictories("reversi") == 0);
    CHECK(newPlayer.getDefeats("reversi") == 0);
    CHECK(newPlayer.getVictories("connectFour") == 0);
    CHECK(newPlayer.getDefeats("connectFour") == 0);
    CHECK(newPlayer.getVictories("ticTacToe") == 0);
    CHECK(newPlayer.getDefeats("ticTacToe") == 0);

    // Limpa o arquivo criado
    std::remove("testPlayerData.txt");
  }
}