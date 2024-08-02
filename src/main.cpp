#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Player.hpp"

void readPlayersFromFile(const std::string filename, std::vector<Player>& players){

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Erro leitura do arquivo: " << filename << std::endl;
        return;
    }

    while (!infile.eof()) {
        Player player;
        player.readPlayers(infile);

        if (infile) { 
            players.push_back(player);
        }
    }

    infile.close();
}

void writePlayersToFile(const std::string filename, const std::vector<Player>& players){

    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Erro leitura do arquivo: " << filename << std::endl;
        return;
    }

    for (const auto& player : players) {
        player.writePlayers(outfile);
    }

    outfile.close();
}

void removePlayer(const std::string nickName, std::vector<Player>& players){
    auto it = std::remove_if(players.begin(), players.end(), [&nickName](const Player& player) {
        return player.getNickName() == nickName;
    });

    if (it != players.end()) {
        players.erase(it, players.end());
        std::cout << nickName << " removido com sucesso!" << std::endl;
    } else {
        std::cout << nickName << " não foi encontrado." << std::endl;
    }
}

int main() {
    std::string tipo;
    std::vector<Player> players;
    std::string filename = "players.txt";

    readPlayersFromFile(filename, players);

    while (true) {
        std::cin >> tipo;

        if (tipo == "FS") {
            break;
        } else if (tipo == "CJ") {
            std::string nickName, name;
            std::cin >> nickName >> name;

            Player player(nickName, name);
            std::cout << "Foi." << std::endl;
            players.push_back(player);

        } else if (tipo == "RJ") {
            std::string nickName;
            std::cin >> nickName;

            removePlayer(nickName, players);

        } else if (tipo == "LJ") {

            for (auto& player : players)
                player.showStatistics();

        } else if (tipo == "EP"){

            players[0].setVictories("reversi");

        }else {
            std::cout << "Opção inválida." << std::endl;
        }
    }

    writePlayersToFile(filename, players);
    return 0;
}