#include "Player.hpp"
#include <iostream>
#include <string>

/**
 * @file Player.cpp
 * @brief Implementação da classe Player que representa um jogador.
 */

/**
 * @brief Construtor da classe Player.
 * 
 * Inicializa um jogador com seu apelido e nome, e define as estatísticas 
 * de vitórias e derrotas para cada jogo (Reversi, Connect Four, TicTacToe) como zero.
 * 
 * @param nickName Apelido do jogador.
 * @param name Nome do jogador.
 */
Player::Player(std::string nickName, std::string name) : 
  _nickName(nickName), _name(name) {
    _victories["reversi"] = 0;
    _victories["connectFour"] = 0;
    _victories["ticTacToe"] = 0;
    _defeats["reversi"] = 0;
    _defeats["connectFour"] = 0;
    _defeats["ticTacToe"] = 0;
  }

/**
 * @brief Destrutor da classe Player.
 * 
 * Destrói o objeto Player.
 */
Player::~Player() {}

/**
 * @brief Exibe as estatísticas do jogador.
 * 
 * Mostra o apelido, nome, número de vitórias e derrotas para cada jogo.
 */
void Player::showStatistics() const {
  std::cout << std::endl;
  std::cout << _nickName << " " << _name << std::endl;
  std::cout << "REVERSI   - V: " << _victories.at("reversi") << " D: " << _defeats.at("reversi") << std::endl;
  std::cout << "LIG4      - V: " << _victories.at("connectFour") << " D: " << _defeats.at("connectFour") << std::endl;
  std::cout << "TICTACTOE - V: " << _victories.at("ticTacToe") << " D: " << _defeats.at("ticTacToe") << std::endl;
}

/**
 * @brief Lê os dados dos jogadores de um arquivo.
 * 
 * Carrega o apelido, nome, vitórias e derrotas do jogador a partir de um arquivo de entrada.
 * 
 * @param in Stream de entrada do arquivo.
 */
void Player::readPlayers(std::ifstream& in) {
  in >> _nickName >> _name;
  in >> _victories["reversi"] >> _defeats["reversi"];
  in >> _victories["connectFour"] >> _defeats["connectFour"];
  in >> _victories["ticTacToe"] >> _defeats["ticTacToe"];
}

/**
 * @brief Escreve os dados dos jogadores em um arquivo.
 * 
 * Salva o apelido, nome, vitórias e derrotas do jogador em um arquivo de saída.
 * 
 * @param out Stream de saída do arquivo.
 */
void Player::writePlayers(std::ofstream& out) const {
  out << _nickName << " " << _name << " ";
  out << _victories.at("reversi") << " " << _defeats.at("reversi") << " ";
  out << _victories.at("connectFour") << " " << _defeats.at("connectFour") << " ";
  out << _victories.at("ticTacToe") << " " << _defeats.at("ticTacToe") << std::endl;
}

/**
 * @brief Obtém o nome do jogador.
 * 
 * @return std::string Retorna o nome do jogador.
 */
std::string Player::getName() const {
  return _name;
}

/**
 * @brief Obtém o apelido do jogador.
 * 
 * @return std::string Retorna o apelido do jogador.
 */
std::string Player::getNickName() const {
  return _nickName;
}

/**
 * @brief Incrementa o número de vitórias para um jogo específico.
 * 
 * Aumenta o contador de vitórias do jogador para o jogo especificado.
 * 
 * @param gameName Nome do jogo (ex: "reversi", "connectFour", "ticTacToe").
 */
void Player::setVictories(std::string gameName) {
  _victories[gameName]++;
}

/**
 * @brief Incrementa o número de derrotas para um jogo específico.
 * 
 * Aumenta o contador de derrotas do jogador para o jogo especificado.
 * 
 * @param gameName Nome do jogo (ex: "reversi", "connectFour", "ticTacToe").
 */
void Player::setDefeats(std::string gameName) {
  _defeats[gameName]++;
}
