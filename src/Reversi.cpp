/**
 * @file Reversi.cpp
 * @brief Implementação da classe Reversi para o jogo Reversi.
 */

#include "Game.hpp"
#include "Reversi.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

/**
 * @brief Construtor da classe Reversi.
 * 
 * @param rows Número de linhas do tabuleiro.
 * @param cols Número de colunas do tabuleiro.
 */

Reversi::Reversi(int rows, int cols) : Game(rows, cols) {
  _board[_defaultRows/2 - 1][_defaultCols/2 - 1] = "X";
  _board[_defaultRows/2][_defaultCols/2 - 1] = "O";
  _board[_defaultRows/2 - 1][(_defaultCols)/2] = "O";
  _board[_defaultRows/2][(_defaultCols)/2] = "X";
}

/**
 * @brief Verifica se há uma peça do oponente adjacente a uma posição.
 * 
 * @param rows Linha da posição a ser verificada.
 * @param cols Coluna da posição a ser verificada.
 * @param watching Peça do outro jogador.
 * @return true se há uma peça do oponente adjacente, false caso contrário.
 */

bool Reversi::thereIsNearby(int rows, int cols, std::string watching) {

  bool top = (rows > 0);
  bool bottom = (rows + 1 < _defaultRows);
  bool left = (cols > 0);
  bool right = (cols + 1 < _defaultCols);

  if (
    (bottom && _board[rows + 1][cols] == watching) ||
    (top && _board[rows - 1][cols] == watching) ||
    (right && _board[rows][cols + 1] == watching) ||
    (left && _board[rows][cols - 1] == watching) ||
    (bottom && right && _board[rows + 1][cols + 1] == watching) ||
    (bottom && left && _board[rows + 1][cols - 1] == watching) ||
    (top && right && _board[rows - 1][cols + 1] == watching) ||
    (top && left && _board[rows - 1][cols - 1] == watching)
  ) {
    return true;
  }

  return false;
}

/**
 * @brief Verifica se há uma conexão entre uma posição e outra peça do mesmo tipo.
 * 
 * @param rows Linha da posição a ser verificada.
 * @param cols Coluna da posição a ser verificada.
 * @param turn Peça do jogador atual.
 * @param watching Peça do outro jogador.
 * @return true se há conexão, false caso contrário.
 */

bool Reversi::thereIsConnection(int rows, int cols, std::string turn, std::string watching) {
  bool playable = false;

  if(!(rows == _defaultRows-1)) {
    if(_board[rows+1][cols] == watching) {            //Embaixo
      for(int i = rows+1; i < _defaultRows; i++) {
        if(_board[i][cols] == watching){
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == turn) {
          playable = true;
          break;
        }
      }
    }

    if(cols != _defaultCols-1) {
      if(_board[rows+1][cols+1] == watching) {     //Embaixo-Direita
              
        for(int i = rows+1, j = cols+1; i < _defaultRows && j < _defaultCols ; i++, j++) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            playable = true;
            break;
          }
        }
      }
    }

    if (cols != 0) {
      if(_board[rows+1][cols-1] == watching) {     //Embaixo-Esquerda
              
        for(int i = rows+1, j = cols-1; i < _defaultRows && j >= 0 ; i++, j--) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            playable = true;
            break;
          }
        }
      }
    }
  }

  if(rows != 0) {
    if(_board[rows-1][cols] == watching) {       //Em cima
      for(int i = rows-1; i >= 0; i--) {
        if(_board[i][cols] == watching) {
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == turn) {
          playable = true;
          break;
        }
      }
    }
    if(cols != _defaultCols-1) {
      if(_board[rows-1][cols+1] == watching) {     //Em cima-Direita
                      
        for(int i = rows-1, j = cols+1; i >= 0 && j < _defaultCols ; i--, j++) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            playable = true;
            break;
          }
        }   
      }
    }

    if (cols != 0) {
      if(_board[rows-1][cols-1] == watching) {     //Em cima-Esquerda
                      
        for(int i = rows-1, j = cols-1 ; i >= 0 && j >= 0 ; i--, j--) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            playable = true;
            break;
          }
        }
      }
    }
  }

  if(cols != _defaultCols-1) {
    if(_board[rows][cols+1] == watching) {       //Direita
      for(int i = cols+1;i < _defaultCols; i++) {
        if(_board[rows][i] == watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == turn) {
          playable = true;
          break;
        }
      }
    }
  }

  if(cols != 0) {
    if(_board[rows][cols-1] == watching) {       //Esquerda
      for(int i = cols-1;i >= 0; i--) {
        if(_board[rows][i] == watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == turn) {
          playable = true;
          break;
        }
      }
    }
  }
  return playable;
}

/**
 * @brief Realiza uma jogada no tabuleiro.
 * 
 * @param rows Linha onde a peça será colocada.
 * @param cols Coluna onde a peça será colocada.
 * @param turn Peça do jogador atual.
 * @param watching Peça do outro jogador.
 */

void Reversi::makeMove(int rows, int cols, std::string turn, std::string watching) {
  _board[rows][cols] = turn;
  if(rows != _defaultRows-1){

    if(_board[rows+1][cols] == watching) {            //Embaixo
      for(int i = rows+1;i < _defaultRows; i++) {
        if(_board[i][cols] == watching) {
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == turn) {
          for(int k = rows+1;k <= i; k++) {
            _board[k][cols] = turn;
          }
          break;
        }
      }
    }

    if(cols != _defaultCols-1) { //Evitar acesso indevido de memÃ³ria
      if(_board[rows+1][cols+1] == watching) {     //Embaixo-Direita
                      
        for(int i = rows+1, j = cols+1; i < _defaultRows && j < _defaultCols ; i++, j++) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            for(int k = rows+1,m = cols+1;k <= i; k++, m++) {
              _board[k][m] = turn;
            }
            break;
          }
        }
      }
    }

    if(cols != 0) { 
      if(_board[rows+1][cols-1] == watching) {     //Embaixo-Esquerda

        for(int i = rows+1, j = cols-1; i < _defaultRows && j >= 0 ; i++, j--) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          }    
          else if(_board[i][j] == turn) {
            for(int k = rows+1,m = cols-1;k <= i; k++, m--) {
              _board[k][m] = turn;
            }
            break;
          }
        }
      }
    }
  }

  if(rows != 0) {
    if(_board[rows-1][cols] == watching) {       //Em cima
      for(int i = rows-1;i >= 0; i--){
        if(_board[i][cols] == watching) {
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == turn) {
          for(int k = rows-1;k >= i; k--) {
            _board[k][cols] = turn;
          }
          break;
        }
      }
    }

    
    if(cols != _defaultCols-1) { 
      if(_board[rows-1][cols+1] == watching) {     //Em cima-Direita
            
        for(int i = rows-1, j = cols+1; i >= 0 && j < _defaultCols ; i--, j++) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            for(int k = rows-1,m = cols+1; k >= i; k--, m++) {
              _board[k][m] = turn;
            }
            break;
          }
        }
      }
    }

    if (cols != 0) {
      if(_board[rows-1][cols-1] == watching) {     //Em cima-Esquerda
                
        for(int i = rows-1, j = cols-1; i >= 0 && j >= 0 ; i--, j--) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            for(int k = rows-1,m = cols-1; k >= i; k--, m--) {
              _board[k][m] = turn;
            }
            break;
          }
        }
      }
    }
  }

  if(cols != _defaultCols-1) {

    if(_board[rows][cols+1] == watching) {                //Direita
      for(int i = cols+1;i < _defaultCols; i++) {
        if(_board[rows][i] == watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == turn) {
          for(int k = cols+1;k <= i; k++) {
            _board[rows][k] = turn;
          }
          break;
        }
      }
    }
  }

  if(cols != 0) {
    if(_board[rows][cols-1] == watching) {       //Esquerda
      for(int i = cols-1;i >= 0; i--) {
        if(_board[rows][i] == watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == turn) {
          for(int k = cols-1;k >= i; k--) {
            _board[rows][k] = turn;
          }
          break;
        }
      }
    }
  }
}

/**
 * @brief Conta o número de peças de cada jogador no tabuleiro.
 */

void Reversi::piecesCounter() {
  int auxXCounter = 0;
  int auxOCounter = 0;
  for(int i = 0;i < _defaultRows; i++) {
    for(int j = 0;j < _defaultCols; j++) {
      if(_board[i][j] == "X") {
        auxXCounter++;
      }
      else if(_board[i][j] == "O") {
        auxOCounter++;
      }
    }
  }
  _xCounter = auxXCounter;
  _oCounter = auxOCounter;
  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;
  std::cout << "|      X = " << _xCounter;         
  std::cout << "      |      O = " << _oCounter << "      |" << std::endl;
  std::cout << "-------------------------------------" << std::endl;
  

}

/**
 * @brief Verifica se o tabuleiro está cheio.
 * 
 * @return true se o tabuleiro está cheio, false caso contrário.
 */

bool Reversi::isBoardFull() const {

  if(_xCounter+_oCounter == _defaultRows*_defaultCols)
    return true;

  return false; 
}

/**
 * @brief Verifica se há alguma jogada possível.
 * @param turn Peça do jogador atual.
 * @param watching Peça do outro jogador.
 * @return true se há jogadas possíveis, false caso contrário.
 */

bool Reversi::isAnyPossiblePlay(std::string turn, std::string watching) {
  for(int i = 0;i < _defaultRows; i++) {
    for(int j = 0;j < _defaultCols; j++) {
      if(_board[i][j] == " ") {
        if(!thereIsNearby(i, j, watching)) {
          continue;
        }
        if(!thereIsConnection(i, j, turn, watching)) {
          continue;
        }
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Realiza uma partida de Reversi entre dois jogadores.
 * 
 * @param player1 Ponteiro para o jogador 1.
 * @param player2 Ponteiro para o jogador 2.
 */

void Reversi::match(Player* player1, Player* player2) {
  int row, col;
  std::string currentPlayer = player1->getNickName();
  std::string outerPlayer = player2->getNickName();

  std::string turn = "X";
  std::string watching = "O";

  printBoard();
  piecesCounter();

  while(1) {
    std::cout << "Vez de " << currentPlayer << " jogar(" << turn << "):" << std::endl << std::endl;
    std::cin >> row;

    if(std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "ERRO: Entrada inválida." << std::endl;
      continue;
    }

    if(row == -1) {
      std::cout << currentPlayer << " desistiu, vitória de " << outerPlayer << "." << std::endl;

      if (outerPlayer == player1->getNickName()) {
        player1->setVictories("reversi");
        player2->setDefeats("reversi");
      } else {
        player1->setDefeats("reversi");
        player2->setVictories("reversi");
      }
      std::cout << std::endl;
      break;
    }

    std::cin >> col;

    if(std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "ERRO: Entrada inválida." << std::endl;
      continue;
    }

    //Necessário pois uma matriz inicia-se com 0,0 e não com 1,1
    row--;
    col--;

    try{
      if(row < 0 || row > _defaultRows - 1 || col < 0 || col > _defaultCols - 1) {
        throw std::out_of_range("Posição fora dos limites do tabuleiro!");
      }
      if(_board[row][col] != " ") {
        throw std::invalid_argument("Posição já ocupada!");
      }
      if(!thereIsNearby(row, col, watching)) {
        throw std::invalid_argument("Não tem peça oposta adjacente.");
      }
      if(!thereIsConnection(row, col, turn, watching)) {
        throw std::invalid_argument("Não tem conexão com outra peça do mesmo tipo.");
      }

    }catch (const std::out_of_range& e) {
      std::cout << "ERRO:" << e.what() << std::endl;
      continue;

    }catch (const std::invalid_argument& e) {
      std::cout << "ERRO:" << e.what() << std::endl;
      continue;
      
    }
    makeMove(row, col, turn, watching); //Antigo isPlaying
    
    printBoard();
    piecesCounter();

    if(_xCounter == 0 || _oCounter == 0){
      std::string winner;

      if(_xCounter == 0){
        winner = turn == "O" ? currentPlayer : outerPlayer;                                //caso em que um player zera suas peças
      }
      else if(_oCounter == 0){
        winner = turn == "X" ? currentPlayer : outerPlayer;
      }

      std::cout << std::endl << "Parabéns " << winner << "! Você venceu!" << std::endl;

      if (winner == player1->getNickName()) {
        player1->setVictories("reversi");
        player2->setDefeats("reversi");
      } else {
        player1->setDefeats("reversi");
        player2->setVictories("reversi");
      }
      std::cout << std::endl;
      break;
    }


    if(isBoardFull()) {      
      std::string winner;

      if(_xCounter > _oCounter) {
        winner = turn == "X" ? currentPlayer : outerPlayer;
      } else if(_xCounter < _oCounter) {
        winner = turn == "O" ? currentPlayer : outerPlayer;
      } else {
        std::cout << "O jogo terminou em empate!" << std::endl;
        break;
      }
      std::cout << std::endl << "Parabéns " << winner << "! Você venceu!" << std::endl;

      if (winner == player1->getNickName()) {
        player1->setVictories("reversi");
        player2->setDefeats("reversi");
      } else {
        player1->setDefeats("reversi");
        player2->setVictories("reversi");
      }
      std::cout << std::endl;
      break;
    }

    std::string aux = turn;
    turn = watching;
    watching = aux;

    aux = currentPlayer;
    currentPlayer = outerPlayer;
    outerPlayer = aux;
      
    if(!isAnyPossiblePlay(turn, watching)) {
      std::cout << std::endl << "Nao há jogadas possíveis para o(a) jogador(a) " << currentPlayer << std::endl;
      std::string aux = turn;
      turn = watching;
      watching = aux;

      aux = currentPlayer;
      currentPlayer = outerPlayer;
      outerPlayer = aux;
    }

  }
}