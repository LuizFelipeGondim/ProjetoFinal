#include "GameBoard.hpp"
#include "Reversi.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

GameBoard::GameBoard() {
  readPlayersFromFile();
}

GameBoard::~GameBoard() {
  for(Player* player : _players)
    delete player;

  _players.clear();
}

bool GameBoard::searchPlayer(std::string nickName) const {
  for(Player* player : _players)
    if(player->getNickName() == nickName)
      return true;
  
  return false;
}

void GameBoard::listStatistics(std::string orderType) const {

  if(_players.empty()) {
    std::cout << "Não há jogadores!" << std::endl;
    std::cout << std::endl;
    return;
  }

  std::vector<Player*> sortedPlayers = _players;

  if(orderType == "A") {
    std::sort(
      sortedPlayers.begin(), 
      sortedPlayers.end(), 
      [](const Player* a, const Player* b) {
          return a->getNickName() < b->getNickName();
      });
    
  } else if (orderType == "N") {
    std::sort(
      sortedPlayers.begin(), 
      sortedPlayers.end(), 
      [](const Player* a, const Player* b) {
          return a->getName() < b->getName();
      });
  }

  for(Player* player : sortedPlayers)
    player->showStatistics();

  std::cout << std::endl;
}

void GameBoard::registerPlayer(std::string nickName, std::string name) {
  _players.push_back(new Player(nickName, name));
}

void GameBoard::removePlayer(std::string nickName) {

  for (auto it = _players.begin(); it != _players.end(); ) {
    if ((*it)->getNickName() == nickName) {
      delete *it;
      it = _players.erase(it); 
      break;
    } else {
      ++it;
    }
  }
}

void GameBoard::startGame(
  std::string game, 
  std::string nickNamePlayer1, 
  std::string nickNamePlayer2
) {
  Player* player1;
  Player* player2;

  for(Player* player : _players) {
    if (player->getNickName() == nickNamePlayer1) {
      player1 = player;
      break;
    }
  }

  for(Player* player : _players) {
    if (player->getNickName() == nickNamePlayer2) {
      player2 = player;
      break;
    }
  }

  if (game == "reversi") {
    Reversi reversi(8, 8);

    reversi.match(player1, player2);

  } else {

    int choice;
    int rows = 0, cols = 0;

    while (true) {
        std::cout << "Escolha o tamanho do Tabuleiro:\n";
        std::cout << "1. 5x6\n";
        std::cout << "2. 6x7\n";
        std::cout << "3. 7x8\n";
        std::cout << "Digite o número da opção desejada: ";

        try{
          if(std::cin >> choice && choice >= 1 && choice <= 3) {
            rows = 4 + choice; // 5, 6, 7
            cols = 5 + choice; // 6, 7, 8
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; 
          }
          else {
            throw std::out_of_range("Entrada inválida. Digite um número de 1 a 3!");
          }

        }catch (const std::out_of_range& e) {
          std::cout << "ERRO:" << e.what() << std::endl << std::endl;
          continue;
        }
    }

    ConnectFour lig4(rows, cols);

    std::cout << std::endl;
    lig4.match(player1, player2);
  }

}

void GameBoard::readPlayersFromFile() {

std::ifstream infile(FILENAME);
  if (!infile) {
    std::cerr << "Erro na leitura do arquivo: " << FILENAME << std::endl;
    std::cout << "Iniciando o sistema com nenhum jogador cadastrado." << std::endl;
    std::cout << std::endl;
    return;
  }

  Player* player = nullptr;
  while (true) {
    player = new Player();
    player->readPlayers(infile);

    if (!infile) {
      delete player;
      break;
    }

    _players.push_back(player);
  }

  infile.close();
}

void GameBoard::writePlayersToFile() {

  std::ofstream outfile(FILENAME);
  if (!outfile) {
    std::cerr << "Erro ao criar o arquivo: " << FILENAME << std::endl;
    return;
  }

  for (const auto& player : _players) {
    player->writePlayers(outfile);
  }

  outfile.close();
}