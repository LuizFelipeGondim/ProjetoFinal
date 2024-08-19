#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Game.hpp"

/**
 * @brief Classe que representa o jogo Tic Tac Toe (Jogo da Velha).
 */
class TicTacToe : public Game {
  public:
    /**
     * @brief Construtor da classe TicTacToe.
     * Inicializa um tabuleiro 3x3 para o jogo.
     */
    TicTacToe(int rows, int cols);
    
    /**
     * @brief Verifica se há um vencedor no jogo.
     * @return Verdadeiro se houver um vencedor, falso caso contrário.
     */
    bool checkWin() const;

    /**
     * @brief Executa uma jogada no tabuleiro.
     * @param row Linha da jogada.
     * @param col Coluna da jogada.
     * @param symbol Símbolo do jogador.
     * @return Verdadeiro se a jogada for válida, falso caso contrário.
     */
    bool makeMove(int row, int col, const std::string& symbol);

    /**
     * @brief Executa uma partida de Tic Tac Toe entre dois jogadores.
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     */
    void match(Player* player1, Player* player2) override;

};

#endif
