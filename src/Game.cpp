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
