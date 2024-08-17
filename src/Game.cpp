#include "Game.hpp"
#include <iostream>
#include <algorithm>

/**
 * @brief Construtor da classe Game.
 * 
 * Inicializa o tabuleiro com o número de linhas e colunas especificado,
 * preenchendo-o com espaços vazios.
 * 
 * @param rows Número de linhas do tabuleiro.
 * @param scols Número de colunas do tabuleiro.
 */
Game::Game(int rows, int cols) : _defaultRows(rows), _defaultCols(cols) {
    _board.resize(_defaultRows, std::vector<std::string>(_defaultCols, " "));
}

void Game::printBoard() const{
    std::cout << "    ";
  for (int col = 1; col <= _defaultCols; ++col) {
    if (col > 1) {
      std::cout << " " << col << "  ";
    } else {
      std::cout << col << "  ";
    }
  }
  std::cout << std::endl;

  for(int i = 0; i < _defaultRows; ++i) {
    std::cout << i+1 << " | ";

    for(int j = 0; j < _defaultCols; ++j) {
      std::cout << _board[i][j] << " | ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Verifica se o tabuleiro está cheio.
 * @return Verdadeiro se o tabuleiro estiver cheio, falso caso contrário.
 */
bool Game::isBoardFull() const {
    for (const auto& row : _board) {
        for (std::string cell : row) {
            if (cell == " ") return false;
        }
    }
    return true;
}