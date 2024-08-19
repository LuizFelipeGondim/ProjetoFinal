#include "GameBoard.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

/**
 * @brief Construtor da classe GameBoard.
 * 
 * Inicializa a instância de GameBoard e lê os jogadores de um arquivo.
 */
GameBoard::GameBoard() {
  readPlayersFromFile();
}

/**
 * @brief Destrutor da classe GameBoard.
 * 
 * Escreve os jogadores no arquivo antes de destruir a instância.
 */
GameBoard::~GameBoard() {
  writePlayersToFile();
  
  for(Player* player : _players)
    delete player;

  _players.clear();
}

/**
 * @brief Transforma uma string em letras minúsculas.
 * 
 * @param word A palavra a ser transformada.
 * @return A palavra em letras minúsculas.
 */
std::string GameBoard::transformToLowerCase(std::string word) {
  std::transform(word.begin(), word.end(), word.begin(),
      [](unsigned char c){ return std::tolower(c); });

  return word;
}

/**
 * @brief Verifica se um jogador com o apelido fornecido já está registrado.
 * 
 * @param nickName O apelido do jogador.
 * @return Verdadeiro se o jogador for encontrado, falso caso contrário.
 */
bool GameBoard::searchPlayer(std::string nickName) const {
  for(Player* player : _players)
    if(player->getNickName() == nickName)
      return true;
  
  return false;
}

/**
 * @brief Obtém o apelido de um jogador existente a partir da entrada do usuário.
 * 
 * @return O apelido de um jogador válido.
 */
std::string GameBoard::getPlayerNickName() {
  std::string playerNickName;

  while(true){
    try{
      if (!(std::cin >> playerNickName)) {
        throw std::runtime_error("Falha na leitura do jogador.");
      }

      if(!searchPlayer(playerNickName)){
        throw std::invalid_argument("Jogador inválido! Por favor, escolha novamente:");
      }
      else break;
    } catch (const std::invalid_argument& e) {
      std::cout << "ERRO: " << e.what() << std::endl;
    }
  }

  return playerNickName;
}

/**
 * @brief Lista as estatísticas dos jogadores.
 * 
 * As estatísticas podem ser ordenadas por apelido ou nome.
 * 
 * @param orderType O tipo de ordenação desejada ("apelido" ou "nome").
 */
void GameBoard::listStatistics(std::string orderType) const {

  if(_players.empty()) {
    std::cout << "Não há jogadores!" << std::endl;
    std::cout << std::endl;
    return;
  }

  std::vector<Player*> sortedPlayers = _players;

  if(orderType == "apelido") {
    std::sort(
      sortedPlayers.begin(), 
      sortedPlayers.end(), 
      [](const Player* a, const Player* b) {
        std::string aNickName = transformToLowerCase(a->getNickName());
        std::string bNickName = transformToLowerCase(b->getNickName());

        return aNickName < bNickName;
      });
    
  } else if (orderType == "nome") {
    std::sort(
      sortedPlayers.begin(), 
      sortedPlayers.end(), 
      [](const Player* a, const Player* b) {
        std::string aName = transformToLowerCase(a->getName());
        std::string bName = transformToLowerCase(b->getName());

        return aName < bName;
      });
  }

  for(Player* player : sortedPlayers)
    player->showStatistics();

  std::cout << std::endl;
}

/**
 * @brief Retorna o número de jogadores registrados.
 * 
 * @return O número de jogadores.
 */
size_t GameBoard::getNumberOfPlayers() const {
  return _players.size();
}

/**
 * @brief Registra um novo jogador no sistema.
 * 
 * @param nickName O apelido do jogador.
 * @param name O nome real do jogador.
 */
void GameBoard::registerPlayer(std::string nickName, std::string name) {
  _players.push_back(new Player(nickName, name));
}

/**
 * @brief Remove um jogador do sistema.
 * 
 * @param nickName O apelido do jogador a ser removido.
 */
void GameBoard::removePlayer(std::string nickName) {

  for (auto it = _players.begin(); it != _players.end(); ) {
    if ((*it)->getNickName() == nickName) {
      delete *it;
      it = _players.erase(it); 
      break;
    } else {
      ++it;
    }
  }
}

/**
 * @brief Inicia um jogo entre dois jogadores.
 * 
 * O jogo pode ser "reversi", "tictactoe", ou "connect four".
 * 
 * @param game O nome do jogo.
 * @param nickNamePlayer1 O apelido do primeiro jogador.
 * @param nickNamePlayer2 O apelido do segundo jogador.
 */
void GameBoard::startGame(
  std::string game, 
  std::string nickNamePlayer1, 
  std::string nickNamePlayer2
) {
  Player* player1 = nullptr;
  Player* player2 = nullptr;

  for(Player* player : _players) {
    if (player->getNickName() == nickNamePlayer1) {
      player1 = player;
      break;
    }
  }

  for(Player* player : _players) {
    if (player->getNickName() == nickNamePlayer2) {
      player2 = player;
      break;
    }
  }

  if (game == "reversi") {
    Reversi reversi(8, 8);

    reversi.match(player1, player2);

  } else if (game == "tictactoe") {
    TicTacToe ticTacToe(3, 3);

    ticTacToe.match(player1, player2);
  } else {

    int choice;
    int rows = 0, cols = 0;

    while (true) {
        std::cout << "Escolha o tamanho do Tabuleiro:\n";
        std::cout << "1. 5x6\n";
        std::cout << "2. 6x7\n";
        std::cout << "3. 7x8\n";
        std::cout << "Digite o número da opção desejada:\n";

        try{
          if (!(std::cin >> choice)) {
            throw std::runtime_error("Falha na leitura do tamanho do tabuleiro.");
          }

          if(choice >= 1 && choice <= 3) {
            rows = 4 + choice; // 5, 6, 7
            cols = 5 + choice; // 6, 7, 8
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break; 
          }
          else {
            throw std::out_of_range("Entrada inválida. Digite um número de 1 a 3!");
          }

        } catch (const std::out_of_range& e) {
          std::cout << "ERRO:" << e.what() << std::endl << std::endl;
          continue;
        } catch (const std::runtime_error& e) {
          throw;
        }
    }

    ConnectFour lig4(rows, cols);

    lig4.match(player1, player2);
  }

}

/**
 * @brief Lê os jogadores de um arquivo.
 * 
 * Se o arquivo não puder ser lido, o sistema será iniciado sem jogadores.
 */
void GameBoard::readPlayersFromFile() {

std::ifstream infile(FILENAME);
  if (!infile) {
    std::cerr << "Erro na leitura do arquivo: " << FILENAME << std::endl;
    std::cout << "Iniciando o sistema com nenhum jogador cadastrado." << std::endl;
    std::cout << std::endl;
    return;
  }

  Player* player = nullptr;
  
  while (true) {
    player = new Player();
    player->readPlayers(infile);

    if (!infile) {
      delete player;
      break;
    }

    _players.push_back(player);
  }

  infile.close();
}

/**
 * @brief Escreve os jogadores em um arquivo.
 * 
 * Se o arquivo não puder ser criado, um erro será exibido.
 */
void GameBoard::writePlayersToFile() {

  std::ofstream outfile(FILENAME);
  if (!outfile) {
    std::cerr << "Erro ao criar o arquivo: " << FILENAME << std::endl;
    return;
  }

  for (const auto& player : _players) {
    player->writePlayers(outfile);
  }

  outfile.close();
}

/**
 * @brief Remove todos os jogadores do sistema e limpa o arquivo de jogadores.
 */
void GameBoard::clearPlayers() {
    for (Player* player : _players) {
      delete player;
    }
    _players.clear();
    std::ofstream outfile(FILENAME, std::ios::trunc); 
    outfile.close();
}
