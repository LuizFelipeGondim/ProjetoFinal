#ifndef REVERSI_HPP
#define REVERSI_HPP

#include <vector>
#include <string>
#include "Game.hpp"

/**
 * @brief Essa classe representa o jogo Reversi.
 * 
 * Essa classe é derivada da classe "Game" e implementa métodos, regras e lógicas específicas
 * do jogo Reversi
 */
class Reversi : public Game {
  private:
    int _xCounter = 2; ///< Contador de peças X
    int _oCounter = 2; ///< Contador de peças O

  public:
    /**
    * @brief Constroi um jogo Reversi com as dimenções do tabuleiro específicadas
    * 
    * @param rows Número de linhas do tabuleiro.
    * @param cols Número de colunas do tabuleiro.
    */
    Reversi(int rows, int cols);

     /**
     * @brief Retorna o conteúdo da posição especificada no tabuleiro.
     * 
     * @param row A linha da posição.
     * @param col A coluna da posição.
     * @return O conteúdo da posição no tabuleiro.
     */
    std::string getBoardContent(int row, int col) const; 

    /**
      * @brief Verifica se tem uma peça oposta em posições adjacentes
      * 
      * @param rows A linha onde a peça vai ser jogada após a verificação.
      * @param cols A coluna onde a peça vai ser jogada após a verificação.
      * @return true se tem uma peça oposta em posição adjacente, false se não tem.
      */
    bool thereIsNearby(int rows, int cols, std::string watching);

    /**
      * @brief Verifica se existe conexão entre as peças
      * 
      * @param rows A linha da peça que precisa ser verificada.
      * @param cols A coluna da peça que precisa ser verificada.
      * @return True se tem uma conexão, false se não tem.
      */
    bool thereIsConnection(int rows, int cols, std::string turn, std::string watching);

    /**
      * @brief Atualiza o contador de peças X e O
      */
    void piecesCounter();


    /**
      * @brief Checa se existe alguma jogada possível.
      * 
      * @return true se tem alguma jogada possível, false se não tem.
      */
    bool isAnyPossiblePlay(std::string turn, std::string watching);

    /**
      * @brief Verifica se o tabuleiro está cheio.
      * 
      * @return true se o tabuleiro está cheio, false se não estiver.
      */
    bool isBoardFull() const override;


    /**
      * @brief Realiza uma jogada no tabuleiro.
      * 
      * @param rows A linha de sua jogada.
      * @param cols A coluna de sua jogada.
      */
    void makeMove(int rows, int cols, std::string turn, std::string watching);


    /**
      * @brief Começa uma partida entre dois jogadores.
      * 
      * @param player1 Ponteiro para o primeiro jogador.
      * @param player2 Ponteiro para o segundo jogador.
      */
    void match(Player* player1, Player* player2) override;
};

#endif
