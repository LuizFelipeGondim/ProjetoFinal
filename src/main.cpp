#include "../include/GameBoard.hpp"

#include <iostream>
#include <string>
#include <algorithm>
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
      std::cout << "Informe um método ordenação: [A|N]" << std::endl;
      std::cin >> orderType;

      while(orderType != "A" && orderType != "N"){
        std::cout << std::endl;
        std::cout << "Informe um método de ordenação válido: [A|N]" << std::endl;
        std::cin >> orderType; 
      }

      gameBoard.listStatistics(orderType);

    } else if (option == "EP"){
      std::string game, nickNamePlayer1, nickNamePlayer2;
      bool playerExists;

      std::cout << "Informe o jogo: [Reversi|Lig4]" << std::endl;
      std::cin >> game;

      std::transform(game.begin(), game.end(), game.begin(),
        [](unsigned char c){ return std::tolower(c); });

      while(game != "reversi" && game != "lig4"){
        std::cout << std::endl;
        std::cout << "Informe um jogo válido: [Reversi|Lig4]" << std::endl;
        std::cin >> game; 

        std::transform(game.begin(), game.end(), game.begin(),
        [](unsigned char c){ return std::tolower(c); });
      }

      std::cout << "Informe o apelido do primeiro jogador:" << std::endl;
      std::cin >> nickNamePlayer1;
      playerExists = gameBoard.searchPlayer(nickNamePlayer1);

      while(!playerExists){
        std::cout << std::endl;
        std::cout << "Jogador inválido!" << std::endl;
        std::cout << "Por favor, escolha novamente:" << std::endl;
        std::cin >> nickNamePlayer1;
        playerExists = gameBoard.searchPlayer(nickNamePlayer1);
      }

      std::cout << "Informe o apelido do segundo jogador:" << std::endl;
      std::cin >> nickNamePlayer2;
      playerExists = gameBoard.searchPlayer(nickNamePlayer2);

      while(!playerExists || nickNamePlayer1 == nickNamePlayer2){
        std::cout << std::endl;
        std::cout << "Jogador inválido!" << std::endl;
        std::cout << "Por favor, escolha novamente:" << std::endl;
        std::cin >> nickNamePlayer2;
        playerExists = gameBoard.searchPlayer(nickNamePlayer2);
      }
      std::cout << std::endl;
      gameBoard.startGame(game, nickNamePlayer1, nickNamePlayer2);

    } else {
      std::cout << "Opção inválida!" << std::endl;
      std::cout << std::endl;
    }
  }

  gameBoard.writePlayersToFile();

  return 0;
}