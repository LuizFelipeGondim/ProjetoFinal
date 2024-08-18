#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define UNIT_TESTING
#include "Player.hpp"
#include "GameBoard.hpp"
#include <sstream>
#include <fstream>


const std::string GameBoard::FILENAME = "testPlayers.txt";

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

        std::string expectedOutput = "\nfulano1 John\nREVERSI   - V: 0 D: 0\nLIG4      - V: 0 D: 0\nTICTACTOE - V: 0 D: 0\n";
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

        std::string expectedOutput = "\nfulano1 John\nREVERSI   - V: 1 D: 1\nLIG4      - V: 1 D: 2\nTICTACTOE - V: 1 D: 1\n";
        CHECK(oss.str() == expectedOutput);
    }

    SUBCASE("Test readPlayers and writePlayers") {
        // Create a temporary file for testing
        std::ofstream outFile("test_player_data.txt");
        player.writePlayers(outFile);
        outFile.close();

        // Read the player data back in
        Player newPlayer("", "");
        std::ifstream inFile("test_player_data.txt");
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

        // Clean up the temporary file
        std::remove("test_player_data.txt");
    }
}