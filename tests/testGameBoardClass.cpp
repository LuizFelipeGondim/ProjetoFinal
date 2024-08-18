#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "GameBoard.hpp"
#include "Player.hpp"

const std::string GameBoard::FILENAME = "testPlayers.txt";

TEST_CASE("Testing GameBoard class") {

  SUBCASE("Test transformToLowerCase method") {
    GameBoard gb;

    CHECK(gb.transformToLowerCase("HELLO") == "hello");
    CHECK(gb.transformToLowerCase("WORLD") == "world");
    CHECK(gb.transformToLowerCase("TeSt") == "test");
    CHECK(gb.transformToLowerCase("Hello 123!") == "hello 123!");
    CHECK(gb.transformToLowerCase("123!@#") == "123!@#");
    CHECK(gb.transformToLowerCase("NoChange") == "nochange");
    CHECK(gb.transformToLowerCase("") == "");
  }

  SUBCASE("Test player registration and search") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("Fulano", "Silva");
    gb.registerPlayer("beltrano", "gomes");

    CHECK(gb.searchPlayer("Fulano") == true);
    CHECK(gb.searchPlayer("beltrano") == true);
    CHECK(gb.searchPlayer("Luiz") == false);
  }

  SUBCASE("Test removePlayer method") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("Fulano", "Silva");
    gb.registerPlayer("beltrano", "gomes");

    gb.removePlayer("Fulano");
    CHECK(gb.searchPlayer("Fulano") == false);
    CHECK(gb.searchPlayer("beltrano") == true);

    gb.removePlayer("beltrano");
    CHECK(gb.searchPlayer("beltrano") == false);
  }

  SUBCASE("Test getNumberOfPlayers method") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("Fulano", "Silva");
    gb.registerPlayer("beltrano", "gomes");

    CHECK(gb.getNumberOfPlayers() == 2);

    gb.removePlayer("Fulano");
    CHECK(gb.getNumberOfPlayers() == 1);

    gb.removePlayer("beltrano");
    CHECK(gb.getNumberOfPlayers() == 0);
  }
}

TEST_CASE("Test getPlayerNickName method") {
  GameBoard gb;
  gb.clearPlayers();

  gb.registerPlayer("fulano", "silva");
  gb.registerPlayer("beltrano", "gomes");

  SUBCASE("Valid input from an existing player") {

    std::istringstream input("fulano\n"); 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf());

    std::string result = gb.getPlayerNickName();
    CHECK(result == "fulano");

    std::cout.rdbuf(oldCoutBuffer);
    std::cin.rdbuf(oldCinBuffer);
  }

  SUBCASE("Invalid input and repeat") {

    std::istringstream input("sadwec\nfulano\n"); 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(); 
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf()); 

    std::string result = gb.getPlayerNickName();
    CHECK(result == "fulano");

    std::cout.rdbuf(oldCoutBuffer);
    std::cin.rdbuf(oldCinBuffer); 
  }

  SUBCASE("Invalid input and long repeat") {

    std::istringstream input("teste1\nteste2\nteste3\nbeltrano\n"); 
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();  
    std::streambuf* oldCinBuffer = std::cin.rdbuf(input.rdbuf());  

    std::string result = gb.getPlayerNickName();
    CHECK(result == "beltrano");

    std::cout.rdbuf(oldCoutBuffer);
    std::cin.rdbuf(oldCinBuffer);
  }
}

TEST_CASE("Test listStatistics method") {

  SUBCASE("Test listStatistics with sorting by nickname") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("Fulano", "Silva");
    gb.registerPlayer("beltrano", "trindade");

    std::ostringstream oss;
    //Substitui buffer de saída do cout pelo de oss
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

    gb.listStatistics("apelido");

    //Restauracao do buffer de saida do cout
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = 
      "\n" 
      "beltrano trindade\n" 
      "REVERSI   - V: 0 D: 0\n"
      "LIG4      - V: 0 D: 0\n"
      "TICTACTOE - V: 0 D: 0\n"
      "\n"
      "Fulano Silva\n"
      "REVERSI   - V: 0 D: 0\n"
      "LIG4      - V: 0 D: 0\n"
      "TICTACTOE - V: 0 D: 0\n"
      "\n";

    CHECK(oss.str() == expectedOutput);

  }

  SUBCASE("Test listStatistics with sorting by name") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("Fulano", "Silva");
    gb.registerPlayer("beltrano", "trindade");

    std::ostringstream oss;
    //Substitui buffer de saída do cout pelo de oss
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

    gb.listStatistics("nome");

    //Restauracao do buffer de saida do cout
    std::cout.rdbuf(oldCoutBuffer);

    std::string expectedOutput = 
      "\n"
      "Fulano Silva\n"
      "REVERSI   - V: 0 D: 0\n"
      "LIG4      - V: 0 D: 0\n"
      "TICTACTOE - V: 0 D: 0\n"
      "\n" 
      "beltrano trindade\n" 
      "REVERSI   - V: 0 D: 0\n"
      "LIG4      - V: 0 D: 0\n"
      "TICTACTOE - V: 0 D: 0\n"
      "\n";

    CHECK(oss.str() == expectedOutput);

  }
}

TEST_CASE("Test writePlayersToFile method") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("fulano", "silva");
    gb.registerPlayer("beltrano", "gomes");
    gb.registerPlayer("Luiz", "Gondim");

    gb.writePlayersToFile();

    std::ifstream file(gb.FILENAME);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line)) {
      lines.push_back(line);
    }

    REQUIRE(lines.size() == 3); 
    CHECK(lines[0] == "fulano silva 0 0 0 0 0 0"); 
    CHECK(lines[1] == "beltrano gomes 0 0 0 0 0 0");
    CHECK(lines[2] == "Luiz Gondim 0 0 0 0 0 0");

    file.close();
    std::remove(gb.FILENAME.c_str());
}

TEST_CASE("Test readPlayersFromFile method") {
    GameBoard gb;
    gb.clearPlayers();

    std::ofstream file(gb.FILENAME);
    file << "fulano silva 1 0 0 0 0 0\n";
    file << "beltrano gomes 0 0 2 0 0 0\n";
    file.close();

    gb.readPlayersFromFile();

    CHECK(gb.getNumberOfPlayers() == 2);

    std::remove(gb.FILENAME.c_str());
}
  /*SUBCASE("Testa início de jogo") {
    GameBoard gb;
    gb.clearPlayers();

    gb.registerPlayer("Player1", "Name1");
    gb.registerPlayer("Player2", "Name2");

    // This would require real implementations of Reversi, TicTacToe, and ConnectFour for a full test.
    // For now, we'll just ensure that the function doesn't crash.
    CHECK_NOTHROW(gb.startGame("reversi", "Player1", "Player2"));
    CHECK_NOTHROW(gb.startGame("tictactoe", "Player1", "Player2"));
    CHECK_NOTHROW(gb.startGame("connectfour", "Player1", "Player2"));
  }*/

