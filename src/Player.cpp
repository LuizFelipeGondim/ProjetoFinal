#include "../include/Player.hpp"
#include <iostream>
#include <string>

Player::Player(std::string nickName, std::string name) : 
  _nickName(nickName), _name(name){
    _victories["reversi"] = 0;
    _victories["connectFour"] = 0;
    _defeats["reversi"] = 0;
    _defeats["connectFour"] = 0;
  }

Player::~Player(){}

void Player::showStatistics() const{
  std::cout << std::endl;
  std::cout << _nickName << " " << _name << std::endl;
  std::cout << "REVERSI - V: "<< _victories.at("reversi") << " D: " << _defeats.at("reversi") << std::endl;
  std::cout << "LIG4    - V: "<< _victories.at("connectFour") << " D: " << _defeats.at("connectFour") << std::endl;
}

void Player::readPlayers(std::ifstream& in){
  in >> _nickName >> _name;
  in >> _victories["reversi"] >> _defeats["reversi"];
  in >> _victories["connectFour"] >> _defeats["connectFour"];
}

void Player::writePlayers(std::ofstream& out) const{
  out << _nickName << " " << _name << " ";
  out << _victories.at("reversi") << " " << _defeats.at("reversi") << " ";
  out << _victories.at("connectFour") << " " << _defeats.at("connectFour") << std::endl;
}

std::string Player::getName() const{
  return _name;
}

std::string Player::getNickName() const{
  return _nickName;
}

void Player::setVictories(std::string gameName){
  _victories[gameName]++;
}

void Player::setDefeats(std::string gameName){
  _defeats[gameName]++;
}