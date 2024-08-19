#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.hpp"
#include "ConnectFour.hpp"
#include "Reversi.hpp"
#include "TicTacToe.hpp"
#include <string>
#include <vector>

/**
 * @brief Classe que gerencia o tabuleiro e os jogadores.
 *
 * A classe GameBoard é responsável por gerenciar os jogadores, registrar e remover jogadores,
 * iniciar jogos e manter as estatísticas. Ela também gerencia a leitura e escrita dos dados
 * dos jogadores em arquivos.
 */
class GameBoard {
  private:
    /**
     * @brief Vetor de ponteiros para jogadores registrados.
     */
    std::vector<Player*> _players;

  public:
    /**
     * @brief Construtor da classe GameBoard.
     *
     * Inicializa a classe GameBoard e pode realizar operações de configuração inicial.
     */
    GameBoard();

    /**
     * @brief Destrutor da classe GameBoard.
     *
     * Realiza a limpeza de memória e outras operações de finalização necessárias.
     */
    ~GameBoard();

    /**
     * @brief Nome do arquivo onde as informações dos jogadores são armazenadas.
     */
    static const std::string FILENAME;

    /**
     * @brief Transforma uma string para letras minúsculas.
     *
     * @param word A string que será transformada.
     * @return A string transformada em letras minúsculas.
     */
    static std::string transformToLowerCase(std::string word);

    /**
     * @brief Busca um jogador pelo seu apelido.
     *
     * @param nickName O apelido do jogador a ser buscado.
     * @return Verdadeiro se o jogador for encontrado, falso caso contrário.
     */
    bool searchPlayer(std::string nickName) const;

    /**
     * @brief Lista as estatísticas dos jogadores.
     *
     * @param orderType O tipo de ordenação das estatísticas (pode ser alfabética, por número de vitórias, etc.).
     */
    void listStatistics(std::string orderType) const;

    /**
     * @brief Retorna o número de jogadores registrados.
     *
     * @return O número de jogadores atualmente registrados.
     */
    size_t getNumberOfPlayers() const;

    /**
     * @brief Remove um jogador do sistema.
     *
     * @param nickName O apelido do jogador a ser removido.
     */
    void removePlayer(std::string nickName);

    /**
     * @brief Inicia um jogo entre dois jogadores.
     *
     * @param game O nome do jogo a ser iniciado (ex.: "Reversi", "TicTacToe").
     * @param nickNamePlayer1 O apelido do primeiro jogador.
     * @param nickNamePlayer2 O apelido do segundo jogador.
     */
    void startGame(
      std::string game, 
      std::string nickNamePlayer1, 
      std::string nickNamePlayer2
    );

    /**
     * @brief Lê os jogadores do arquivo e os carrega no sistema.
     */
    void readPlayersFromFile();

    /**
     * @brief Escreve os jogadores registrados no arquivo.
     */
    void writePlayersToFile();

    /**
     * @brief Obtém o apelido de um jogador.
     *
     * @return O apelido de um jogador.
     */
    std::string getPlayerNickName();

    /**
     * @brief Registra um novo jogador no sistema.
     *
     * @param nickName O apelido do jogador.
     * @param name O nome do jogador.
     */
    void registerPlayer(std::string nickName, std::string name);

    /**
     * @brief Remove todos os jogadores do sistema.
     *
     * Limpa o vetor de jogadores, removendo todas as instâncias de jogadores.
     */
    void clearPlayers();
};

#endif