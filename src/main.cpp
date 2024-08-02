#include <iostream>
#include <string>
#include <vector>

int main(){
    //const GameBoard gameBoard;
    std::string option;

    while((std::cin >> option) && option != "FS"){

        if (option == "CJ"){
            bool playerExists;
            std::string nickname, name;

            std::cin >> nickname >> name;

            /*
            playerExists = gameBoard.searchPlayer(nickname);

            if(!playerExists){
                gameBoard.registerPlayer(nickname, name);
                std::cout << "Jogador " << nickname << " cadastrado com sucesso!" << std::endl;
            }else{
                std::cout << "ERRO: Player existente!" << std::endl;
            } 
            */

            continue;
        }

        if (option == "RJ"){
            bool playerExists;
            std::string nickname;
            std::cin >> nickname;

            /*
            playerExists = gameBoard.searchPlayer(nickname);
            
            if(playerExists){
                gameBoard.removePlayer(nickname);
                std::cout << "Jogador " << nickname << " removido com sucesso!" << std::endl;
            }else{
                std::cout << "ERRO: Player inexistente!" << std::endl;
            } 
            */
            continue;
        }

        if (option == "LJ"){
            char orderType;
            std::cin >> orderType;

            /*
            while(orderType != 'A' && orderType != 'N'){
                std::cout << "Informe um método ordenação válido: [A|N]" << std::endl;
                std::cin >> orderType; 
            }

            gameBoard.listStatistics();
            */

            continue;
        }

        if (option == "EP") {

            continue;
        }
    }

    return 0;
}

/*
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
*/