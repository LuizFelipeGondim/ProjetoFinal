#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <fstream>
#include <map>

/**
 * @brief Classe que representa um jogador.
 *
 * A classe Player armazena as informações de um jogador, incluindo seu nome, apelido,
 * e estatísticas de vitórias e derrotas em diferentes jogos.
 */
class Player {
  private:
    /**
     * @brief Apelido do jogador.
     */
    std::string _nickName;

    /**
     * @brief Nome real do jogador.
     */
    std::string _name;

    /**
     * @brief Mapa que armazena o número de vitórias do jogador por jogo.
     */
    std::map<std::string, int> _victories;

    /**
     * @brief Mapa que armazena o número de derrotas do jogador por jogo.
     */
    std::map<std::string, int> _defeats;

  public:
    /**
     * @brief Construtor padrão da classe Player.
     *
     * Inicializa um jogador com valores padrão.
     */
    Player() = default;

    /**
     * @brief Construtor que inicializa um jogador com nome e apelido.
     *
     * @param nickName O apelido do jogador.
     * @param name O nome real do jogador.
     */
    Player(std::string nickName, std::string name);

    /**
     * @brief Destrutor da classe Player.
     *
     * Realiza a limpeza de recursos utilizados pelo jogador, se necessário.
     */
    ~Player();

    /**
     * @brief Exibe as estatísticas do jogador.
     *
     * Mostra o número de vitórias e derrotas do jogador em cada jogo.
     */
    void showStatistics() const;

    /**
     * @brief Lê as informações do jogador de um arquivo.
     *
     * @param in O fluxo de entrada de arquivo de onde as informações serão lidas.
     */
    void readPlayers(std::ifstream& in);

    /**
     * @brief Escreve as informações do jogador em um arquivo.
     *
     * @param out O fluxo de saída de arquivo para onde as informações serão escritas.
     */
    void writePlayers(std::ofstream& out) const;

    /**
     * @brief Obtém o nome real do jogador.
     *
     * @return O nome do jogador.
     */
    std::string getName() const;

    /**
     * @brief Obtém o apelido do jogador.
     *
     * @return O apelido do jogador.
     */
    std::string getNickName() const;

    /**
     * @brief Incrementa o número de vitórias do jogador em um determinado jogo.
     *
     * @param gameName O nome do jogo em que a vitória ocorreu.
     */
    void setVictories(std::string gameName);

    /**
     * @brief Incrementa o número de derrotas do jogador em um determinado jogo.
     *
     * @param gameName O nome do jogo em que a derrota ocorreu.
     */
    void setDefeats(std::string gameName);

    /**
     * @brief Obtém o número de vitórias do jogador em um determinado jogo.
     *
     * @param gameName O nome do jogo.
     * @return O número de vitórias no jogo especificado.
     */
    int getVictories(const std::string& gameName) const { return _victories.at(gameName); }

    /**
     * @brief Obtém o número de derrotas do jogador em um determinado jogo.
     *
     * @param gameName O nome do jogo.
     * @return O número de derrotas no jogo especificado.
     */
    int getDefeats(const std::string& gameName) const { return _defeats.at(gameName); }
};

#endif


#endif