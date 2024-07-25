#include <iostream>


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