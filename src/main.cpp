#include "GameBoard.hpp"

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

      try{
        if(!playerExists){
          gameBoard.registerPlayer(nickName, name);
          std::cout << "Jogador " << nickName << " cadastrado com sucesso!" << std::endl;
          std::cout << std::endl;
        }
        else {
          throw std::invalid_argument("Jogador existente!");
        }

      }catch (const std::invalid_argument& e) {
        std::cout << "ERRO:" << e.what() << std::endl << std::endl;
        continue;
      }

    }else if (option == "RJ"){
      bool playerExists;
      std::string nickName;
      std::cin >> nickName;

      playerExists = gameBoard.searchPlayer(nickName);
      
      try{
        if(playerExists){
          gameBoard.removePlayer(nickName);
          std::cout << "Jogador " << nickName << " removido com sucesso!" << std::endl;
        }
        else {
          throw std::invalid_argument("Jogador Existente!");
        }

      }catch (const std::invalid_argument& e) {
        std::cout << "ERRO:" << e.what() << std::endl << std::endl;
        continue;
      }

    }else if (option == "LJ"){
      std::string orderType;
      std::cout << "Informe um método ordenação: [A|N]" << std::endl;
      std::cin >> orderType;

      while(1){
        try{
          if(orderType != "A" && orderType != "N"){
            throw std::invalid_argument("Informe um método de ordenação válido: [A|N]");
          }
          else break;
        }catch (const std::invalid_argument& e) {
          std::cout << "ERRO:" << e.what() << std::endl << std::endl;
        }
        std::cin >> orderType; 
      }

      gameBoard.listStatistics(orderType);

    } else if (option == "EP"){
      std::string game, nickNamePlayer1, nickNamePlayer2;
      bool playerExists;

      std::cout << "Informe o jogo: [Reversi|Lig4|TicTacToe]" << std::endl;
      std::cin >> game;

      std::transform(game.begin(), game.end(), game.begin(),
        [](unsigned char c){ return std::tolower(c); });

      while(1){
        try{
          if(game != "reversi" && game != "lig4" && game != "tictactoe"){
            throw std::invalid_argument("Informe um jogo válido: [Reversi|Lig4]");
          }
        else break;
        }catch (const std::invalid_argument& e) {
          std::cout << "ERRO:" << e.what() << std::endl << std::endl;
        }
        std::cin >> game;
        std::transform(game.begin(), game.end(), game.begin(),
          [](unsigned char c){ return std::tolower(c); }); 
      }

      std::cout << "Informe o apelido do primeiro jogador:" << std::endl;
      std::cin >> nickNamePlayer1;
      playerExists = gameBoard.searchPlayer(nickNamePlayer1);

      while(1){
        try{
          if(!playerExists){
            throw std::invalid_argument("Jogador inválido!\nPor favor, escolha novamente:");
          }
        else break;
        }catch (const std::invalid_argument& e) {
          std::cout << "ERRO:" << e.what() << std::endl << std::endl;
        }
        std::cin >> nickNamePlayer1;
        playerExists = gameBoard.searchPlayer(nickNamePlayer1);
      }

      std::cout << "Informe o apelido do segundo jogador:" << std::endl;
      std::cin >> nickNamePlayer2;
      playerExists = gameBoard.searchPlayer(nickNamePlayer2);

      while(1){
        try{
          if(!playerExists || nickNamePlayer1 == nickNamePlayer2){
            throw std::invalid_argument("Jogador inválido!\nPor favor, escolha novamente:");
          }
        else break;
        }catch (const std::invalid_argument& e) {
          std::cout << "ERRO:" << e.what() << std::endl << std::endl;
        }
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

  return 0;
}