#include "GameBoard.hpp"
#include <iostream>

const std::string GameBoard::FILENAME = "players.txt";

int main() {
  GameBoard gameBoard;
  std::string option;

  while(true) {
    std::cout << std::endl;
    std::cout << "Escolha uma opção para interagir com o tabuleiro: " << std::endl;
    std::cout << "CJ - Cadastrar jogador" << std::endl;
    std::cout << "RJ - Remover jogador" << std::endl;
    std::cout << "LJ - Listar jogadores" << std::endl;
    std::cout << "EP - Entrar na partida" << std::endl;
    std::cout << "FS - Sair do tabuleiro" << std::endl << std::endl;
    std::cin >> option;

    try {
      if (option == "CJ") {

        std::string nickName, name;

        std::cout << "Informe o apelido e o nome do jogador, respectivamente:" << std::endl;
        std::cin >> nickName >> name;

        if (gameBoard.searchPlayer(nickName)) {
          throw std::invalid_argument("Jogador existente!");
        }

        gameBoard.registerPlayer(nickName, name);
        std::cout << "Jogador " << nickName << " cadastrado com sucesso!" << std::endl;

      } else if (option == "RJ") {

        std::string nickName;

        std::cout << "Informe o apelido do jogador a ser removido:" << std::endl;
        std::cin >> nickName;

        if (!gameBoard.searchPlayer(nickName)) {
          throw std::invalid_argument("Jogador não encontrado!");
        }

        gameBoard.removePlayer(nickName);
        std::cout << "Jogador " << nickName << " removido com sucesso!" << std::endl;

      } else if (option == "LJ") {

        std::string orderType;
        std::cout << "Informe um método de ordenação: [Apelido|Nome]" << std::endl;

        while (true) {
          try{
            std::cin >> orderType;
            orderType = gameBoard.transformToLowerCase(orderType);

            if(orderType != "apelido" && orderType != "nome"){
              throw std::invalid_argument("Informe um método de ordenação válido: [Apelido|Nome]");
            }
            else break;
          }catch (const std::invalid_argument& e) {
            std::cout << "ERRO: " << e.what() << std::endl;
          }
        }

        gameBoard.listStatistics(orderType);

      } else if (option == "EP") {

        std::string game, playerOneNickName, playerTwoNickName;
        
        if (gameBoard.getNumberOfPlayers() < 2) {
          throw std::runtime_error("Número insuficiente de jogadores. Pelo menos 2 jogadores são necessários.");
        }

        std::cout << "Informe o jogo: [Reversi|Lig4|TicTacToe]" << std::endl;

        while(true){
          try{
            std::cin >> game;
            game = gameBoard.transformToLowerCase(game);

            if(game != "reversi" && game != "lig4" && game != "tictactoe"){
              throw std::invalid_argument("Informe um jogo válido: [Reversi|Lig4|TicTacToe]");
            }
            else break;

          }catch (const std::invalid_argument& e) {
            std::cout << "ERRO:" << e.what() << std::endl;
          }
        }

        std::cout << "Informe o apelido do primeiro jogador:" << std::endl;
        playerOneNickName = gameBoard.getPlayerNickName();
        

        std::cout << "Informe o apelido do segundo jogador:" << std::endl;
        playerTwoNickName = gameBoard.getPlayerNickName();

        while(true){
          try{
            if(playerOneNickName == playerTwoNickName){
              throw std::invalid_argument("Jogador inválido!\nPor favor, escolha novamente:");
            }
          else break;
          }catch (const std::invalid_argument& e) {
            std::cout << "ERRO:" << e.what() << std::endl;
          }
          playerTwoNickName = gameBoard.getPlayerNickName();
        }

        std::cout << std::endl;
        gameBoard.startGame(game, playerOneNickName, playerTwoNickName);
        
      } else if (option == "FS") {
        std::cout << "Finalizando o tabuleiro..." << std::endl;
        break;

      } else {
        throw std::invalid_argument("Opção inválida!");
      }
    } catch (const std::exception& e) {
      std::cout << "ERRO: " << e.what() << std::endl;
    }
  }
  
  return 0;
}