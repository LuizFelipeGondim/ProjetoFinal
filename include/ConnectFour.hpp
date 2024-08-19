#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include "Game.hpp"
#include <vector>
#include <string>

/**
 * @brief Classe que representa o jogo Conecta 4.
 */
class ConnectFour : public Game {
  private:

    /**
     * @brief Verifica se há uma linha horizontal de quatro peças do jogador atual.
     * @param currentPiece Representa a peça atual.
     * @return Verdadeiro se houver uma linha horizontal de quatro peças, falso caso contrário.
     */
    bool checkHorizontal(std::string currentPiece) const;

    /**
     * @brief Verifica se há uma linha vertical de quatro peças do jogador atual.
     * @param currentPiece Representa a peça atual.
     * @return Verdadeiro se houver uma linha vertical de quatro peças, falso caso contrário.
     */
    bool checkVertical(std::string currentPiece) const;

    /**
     * @brief Verifica se há uma linha diagonal de quatro peças do jogador atual.
     * @param currentPiece Representa a peça atual.
     * @return Verdadeiro se houver uma linha diagonal de quatro peças, falso caso contrário.
     */
    bool checkDiagonal(std::string currentPiece) const;

    /**
     * @brief Verifica se a jogada é válida.
     * @param col A coluna onde a jogada será feita.
     * @return Verdadeiro se a jogada é válida, falso caso contrário.
     */
    bool isValidMove(int col) const;


    /**
     * @brief Imprime o estado atual do tabuleiro.
     */
    void printBoard() const override;


  public:
    /**
     * @brief Construtor da classe ConnectFour.
     * @param rows Número de linhas do tabuleiro.
     * @param cols Número de colunas do tabuleiro.
     */
    ConnectFour(int rows, int cols);
    
    /**
     * @brief Conta o número de possíveis formas de ganhar para o jogador atual.
     * @param currentPiece Representa a peça atual.
     * @return Número de possíveis formas de ganhar.
     */
    void countPossibleWins(std::string currentPiece) const;
    
    /**
     * @brief Verifica se o jogador atual ganhou.
     * @param currentPiece Representa a peça atual.
     * @return Verdadeiro se o jogador ganhou, falso caso contrário.
     */
    bool checkWin(std::string currentPiece) const;

    /**
     * @brief Faz uma jogada, colocando uma peça na coluna especificada.
     * @param col A coluna onde a peça será colocada.
     * @param currentPiece Representa a peça atual.
     * @return Verdadeiro se a jogada for bem-sucedida, falso caso contrário.
     */
    bool makeMove(int col, std::string currentPiece);


    /**
     * @brief Executa uma partida entre dois jogadores.
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     */
    void match(Player* player1, Player* player2) override;
};

#endif
