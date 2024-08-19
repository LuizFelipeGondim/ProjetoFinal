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
 * @param cols Número de colunas do tabuleiro.
 */
Game::Game(int rows, int cols) : _defaultRows(rows), _defaultCols(cols) {
  _board.resize(_defaultRows, std::vector<std::string>(_defaultCols, " "));
}

/**
 * @brief Imprime o tabuleiro no console.
 * 
 * Este método exibe o estado atual do tabuleiro de jogo, mostrando as 
 * linhas e colunas com os valores correspondentes em cada célula.
 */
void Game::printBoard() const {
    std::cout << "    ";
    for (int col = 1; col <= _defaultCols; ++col) {
        if (col > 1) {
            std::cout << " " << col << "  ";
        } else {
            std::cout << col << "  ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < _defaultRows; ++i) {
        std::cout << i + 1 << " | ";

        for (int j = 0; j < _defaultCols; ++j) {
            std::cout << _board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Verifica se o tabuleiro está cheio.
 * 
 * Este método verifica se todas as células do tabuleiro foram preenchidas,
 * o que indicaria que o jogo terminou em um empate, caso nenhuma condição
 * de vitória tenha sido atendida.
 * 
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
