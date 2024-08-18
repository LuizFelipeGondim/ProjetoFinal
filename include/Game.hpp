#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <vector>
#include <string>

/**
 * @brief Classe base abstrata que representa um jogo genérico.
 */
class Game {
  protected:
    std::vector<std::vector<std::string>> _board; /**< Matriz que representa o tabuleiro do jogo. */
    int _defaultRows; /**< Número padrão de linhas do tabuleiro. */
    int _defaultCols; /**< Número padrão de colunas do tabuleiro. */


  public:
    /**
     * @brief Construtor da classe Game.
     * @param rows Número de linhas do tabuleiro.
     * @param cols Número de colunas do tabuleiro.
     */
    Game(int rows, int cols);

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Game() = default;
    
    /**
     * @brief Imprime o estado atual do tabuleiro.
     */
    virtual void printBoard() const;

    /**
     * @brief Verifica se o tabuleiro está cheio.
     * @return Verdadeiro se o tabuleiro estiver cheio, falso caso contrário.
     */
    virtual bool isBoardFull() const;

    /**
     * @brief Executa uma partida entre dois jogadores.
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     */
    virtual void match(Player* player1, Player* player2) = 0;
};

#endif
