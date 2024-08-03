#include "../include/GameBoard.hpp"

#include <iostream>
#include <string>
#include <algorithm>

GameBoard::GameBoard(){
  readPlayersFromFile();
}

GameBoard::~GameBoard(){
  for(Player* player : _players)
    delete player;

  _players.clear();
}

bool GameBoard::searchPlayer(std::string nickName) const{
  for(auto& player : _players)
    if(player->getNickName() == nickName)
      return true;
  
  return false;
}

void GameBoard::listStatistics(std::string orderType) const{

  if(_players.empty()){
    std::cout << "Não há jogadores!" << std::endl;
    std::cout << std::endl;
    return;
  }

  std::vector<Player*> sortedPlayers = _players;

  if(orderType == "A"){
    std::sort(
      sortedPlayers.begin(), 
      sortedPlayers.end(), 
      [](const Player* a, const Player* b) {
          return a->getNickName() < b->getNickName();
      });
    
  } else if (orderType == "N"){
    std::sort(
      sortedPlayers.begin(), 
      sortedPlayers.end(), 
      [](const Player* a, const Player* b) {
          return a->getName() < b->getName();
      });
  }

  for(Player* player : sortedPlayers)
    player->showStatistics();
}

void GameBoard::registerPlayer(std::string nickName, std::string name){
  _players.push_back(new Player(nickName, name));
}

void GameBoard::removePlayer(std::string nickName){

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

void GameBoard::readPlayersFromFile(){

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

void GameBoard::writePlayersToFile(){

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