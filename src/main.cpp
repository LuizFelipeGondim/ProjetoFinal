#include "../include/GameBoard.hpp"

#include <iostream>
#include <string>
#include <vector>

const std::string GameBoard::FILENAME = "players.txt";

int main(){
  GameBoard gameBoard;
  std::string option;

  while((std::cin >> option) && option != "FS"){

    if (option == "CJ"){
      bool playerExists;
      std::string nickName, name;

      std::cin >> nickName >> name;

      playerExists = gameBoard.searchPlayer(nickName);

      if(!playerExists){
        gameBoard.registerPlayer(nickName, name);
        std::cout << "Jogador " << nickName << " cadastrado com sucesso!" << std::endl;
      }else{
        std::cout << "ERRO: Jogador existente!" << std::endl;
      }

      std::cout << std::endl;

    } else if (option == "RJ"){
      bool playerExists;
      std::string nickName;
      std::cin >> nickName;

      playerExists = gameBoard.searchPlayer(nickName);
      
      if(playerExists){
        gameBoard.removePlayer(nickName);
        std::cout << "Jogador " << nickName << " removido com sucesso!" << std::endl;
      }else{
        std::cout << "ERRO: Jogador inexistente!" << std::endl;
      } 
      
      std::cout << std::endl;

    } else if (option == "LJ"){
      std::string orderType;

      std::cout << std::endl;
      std::cout << "Informe um método ordenação: [A|N]" << std::endl;
      std::cin >> orderType;

      while(orderType != "A" && orderType != "N"){
        std::cout << std::endl;
        std::cout << "Informe um método de ordenação válido: [A|N]" << std::endl;
        std::cin >> orderType; 
      }

      gameBoard.listStatistics(orderType);

    } else if (option == "EP"){

    } else {
      std::cout << "Opção inválida!" << std::endl;
      std::cout << std::endl;
    }
  }

  gameBoard.writePlayersToFile();

  return 0;
}