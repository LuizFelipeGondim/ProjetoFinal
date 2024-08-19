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
 * Inicializa o tabuleiro com as peças iniciais do jogo Reversi.
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
 * Atualiza o tabuleiro após a jogada, virando as peças do oponente conforme necessário.
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

    if(cols != _defaultCols-1) { //Evitar acesso indevido de memória
      if(_board[rows+1][cols+1] == watching) {     //Embaixo-Direita
        for(int i = rows+1, j = cols+1; i < _defaultRows && j < _defaultCols ; i++, j++) {
          if(_board[i][j] == watching) {
            continue;
          }
          else if(_board[i][j] == " ") {
            break;
          } 
          else if(_board[i][j] == turn) {
            for(int k = rows+1, l = cols+1; k <= i && l <= j ; k++, l++) {
              _board[k][l] = turn;
            }
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
            for(int k = rows+1, l = cols-1; k <= i && l >= j ; k++, l--) {
              _board[k][l] = turn;
            }
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
          for(int k = rows-1; k >= i; k--) {
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
            for(int k = rows-1, l = cols+1; k >= i && l <= j ; k--, l++) {
              _board[k][l] = turn;
            }
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
            for(int k = rows-1, l = cols-1 ; k >= i && l >= j ; k--, l--) {
              _board[k][l] = turn;
            }
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
 * @brief Verifica se a peça atual pode ser colocada em uma posição específica.
 * 
 * @param rows Linha onde a peça será colocada.
 * @param cols Coluna onde a peça será colocada.
 * @param turn Peça do jogador atual.
 * @param watching Peça do outro jogador.
 * @return true se a peça pode ser colocada, false caso contrário.
 */
bool Reversi::canPlay(int rows, int cols, std::string turn, std::string watching) {
  bool playable = false;

  if(_board[rows][cols] != " " || !thereIsNearby(rows, cols, watching)){
    return false;
  }

  playable = thereIsConnection(rows, cols, turn, watching);
  return playable;
}

/**
 * @brief Executa a jogada de um jogador.
 * 
 * Recebe as coordenadas da jogada, verifica se a jogada é válida e, se for, a realiza.
 * 
 * @param turn Peça do jogador atual.
 */
void Reversi::playMove(std::string turn) {
  int rows, cols;
  std::string watching = (turn == "X") ? "O" : "X";

  while (true) {
    std::cout << "Player " << turn << " - Digite linha e coluna: ";
    std::cin >> rows >> cols;

    if (std::cin.fail() || rows < 0 || rows >= _defaultRows || cols < 0 || cols >= _defaultCols) {
      std::cin.clear(); // Limpa o estado de erro
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
      std::cout << "Entrada inválida! Por favor, insira números válidos.\n";
      continue;
    }

    if (canPlay(rows, cols, turn, watching)) {
      makeMove(rows, cols, turn, watching);
      break;
    } else {
      std::cout << "Jogada inválida! Tente novamente.\n";
    }
  }
}
