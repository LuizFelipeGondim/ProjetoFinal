#include "Game.hpp"
#include "Reversi.hpp"
#include <iostream>
#include <limits>
#include <string>

Reversi::Reversi(int rows, int cols) : Game(rows, cols) {
  _board[_defaultRows/2 - 1][_defaultCols/2 - 1] = "X";
  _board[_defaultRows/2][_defaultCols/2 - 1] = "O";
  _board[_defaultRows/2 - 1][(_defaultCols)/2] = "O";
  _board[_defaultRows/2][(_defaultCols)/2] = "X";
}

bool Reversi::thereIsNearby(int rows, int cols) {

  bool top = (rows > 0);
  bool bottom = (rows + 1 < _defaultRows);
  bool left = (cols > 0);
  bool right = (cols + 1 < _defaultCols);

  if (
    (bottom && _board[rows + 1][cols] == _watching) ||
    (top && _board[rows - 1][cols] == _watching) ||
    (right && _board[rows][cols + 1] == _watching) ||
    (left && _board[rows][cols - 1] == _watching) ||
    (bottom && right && _board[rows + 1][cols + 1] == _watching) ||
    (bottom && left && _board[rows + 1][cols - 1] == _watching) ||
    (top && right && _board[rows - 1][cols + 1] == _watching) ||
    (top && left && _board[rows - 1][cols - 1] == _watching)
  ) {
    return true;
  }

  return false;
}

bool Reversi::thereIsConnection(int rows, int cols) {
  bool playable = false;

  if(!(rows == _defaultRows-1)) {
    if(_board[rows+1][cols] == _watching) {            //Embaixo
      for(int i = rows+1; i < _defaultRows; i++) {
        if(_board[i][cols] == _watching){
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == _turn) {
          playable = true;
          break;
        }
      }
    }
    if(_board[rows+1][cols+1] == _watching) {     //Embaixo-Direita
             
      for(int i = rows+1, j = cols+1; i < _defaultRows && j < _defaultCols ; i++, j++) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          playable = true;
          break;
        }
      }
    }
    if(_board[rows+1][cols-1] == _watching) {     //Embaixo-Esquerda
             
      for(int i = rows+1, j = cols-1; i < _defaultRows && j >= 0 ; i++, j--) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          playable = true;
          break;
        }
      }
    }
  }
  if(!(rows == 0)) {
    if(_board[rows-1][cols] == _watching) {       //Em cima
      for(int i = rows-1; i >= 0; i--) {
        if(_board[i][cols] == _watching) {
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == _turn) {
          playable = true;
          break;
        }
      }
    }

    if(_board[rows-1][cols+1] == _watching) {     //Em cima-Direita
                     
      for(int i = rows-1, j = cols+1; i >= 0 && j < _defaultCols ; i--, j++) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          playable = true;
          break;
        }
      }   
    }
    if(_board[rows-1][cols-1] == _watching) {     //Em cima-Esquerda
                     
      for(int i = rows-1, j = cols-1 ; i >= 0 && j >= 0 ; i--, j--) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          playable = true;
          break;
        }
      }
    }
  }
  if(!(cols == _defaultCols-1)) {
    if(_board[rows][cols+1] == _watching) {       //Direita
      for(int i = cols+1;i < _defaultCols; i++) {
        if(_board[rows][i] == _watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == _turn) {
          playable = true;
          break;
        }
      }
    }
  }
  if(!(cols == 0)) {
    if(_board[rows][cols-1] == _watching) {       //Esquerda
      for(int i = cols-1;i >= 0; i--) {
        if(_board[rows][i] == _watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == _turn) {
          playable = true;
          break;
        }
      }
    }
  }
  return playable;
}

void Reversi::makeMove(int rows, int cols) {
  _board[rows][cols] = _turn;
  if(!(rows == _defaultRows-1)){
    if(_board[rows+1][cols] == _watching) {            //Embaixo
      for(int i = rows+1;i < _defaultRows; i++) {
        if(_board[i][cols] == _watching) {
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == _turn) {
          for(int k = rows+1;k <= i; k++) {
            _board[k][cols] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows+1][cols+1] == _watching) {     //Embaixo-Direita
                     
      for(int i = rows+1, j = cols+1; i < _defaultRows && j < _defaultCols ; i++, j++) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          for(int k = rows+1,m = cols+1;k <= i; k++, m++) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows+1][cols-1] == _watching) {     //Embaixo-Esquerda

      for(int i = rows+1, j = cols-1; i < _defaultRows && j >= 0 ; i++, j--) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        }    
        else if(_board[i][j] == _turn) {
          for(int k = rows+1,m = cols-1;k <= i; k++, m--) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }
  }
  if(!(rows == 0)) {
    if(_board[rows-1][cols] == _watching) {       //Em cima
      for(int i = rows-1;i >= 0; i--){
        if(_board[i][cols] == _watching) {
          continue;
        }
        else if(_board[i][cols] == " ") {
          break;
        } 
        else if(_board[i][cols] == _turn) {
          for(int k = rows-1;k >= i; k--) {
            _board[k][cols] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows-1][cols+1] == _watching) {     //Em cima-Direita
           
      for(int i = rows-1, j = cols+1; i >= 0 && j < _defaultCols ; i--, j++) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          for(int k = rows-1,m = cols+1; k >= i; k--, m++) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows-1][cols-1] == _watching) {     //Em cima-Esquerda
               
      for(int i = rows-1, j = cols-1; i >= 0 && j >= 0 ; i--, j--) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          for(int k = rows-1,m = cols-1; k >= i; k--, m--) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }
  }
  if(!(cols == _defaultCols-1)) {
    if(_board[rows][cols+1] == _watching) {                //Direita
      for(int i = cols+1;i < _defaultCols; i++) {
        if(_board[rows][i] == _watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == _turn) {
          for(int k = cols+1;k <= i; k++) {
            _board[rows][k] = _turn;
          }
          break;
        }
      }
    }
  }
  if(!(cols == 0)) {
    if(_board[rows][cols-1] == _watching) {       //Esquerda
      for(int i = cols-1;i >= 0; i--) {
        if(_board[rows][i] == _watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == _turn) {
          for(int k = cols-1;k >= i; k--) {
            _board[rows][k] = _turn;
          }
          break;
        }
      }
    }
  }
}

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

bool Reversi::isBoardFull() const {

  if(_xCounter+_oCounter == _defaultRows*_defaultCols)
    return true;

  return false; 
}

bool Reversi::isAnyPossiblePlay() {
  for(int i = 0;i < _defaultRows; i++) {
    for(int j = 0;j < _defaultCols; j++) {
      if(_board[i][j] == " ") {
        if(!thereIsNearby(i, j)) {
          continue;
        }
        if(!thereIsConnection(i, j)) {
          continue;
        }
        return true;
      }
    }
  }
  return false;
}

/*
bool Reversi::gameOver() {
  int x = 0, o = 0;

  for(int i = 0;i < _defaultRows; i++) {
    for(int j = 0;j < _defaultCols; j++) {
      if(_board[i][j] == "X") {
        x += 1;
      }
      else if(_board[i][j] == "O") {
        o += 1;
      }
      else if(_board[i][j] == " ") {
        return false;
      }
    }
  }
  if(x > o) {
    std::cout << "FIM DO JOGO" << std::endl << "X GANHOU!!" << std::endl;
  }
  else if(x < o) {
    std::cout << "FIM DO JOGO" << std::endl << "O GANHOU!!" << std::endl;
  }
  else {
    std::cout << "FIM DO JOGO" << std::endl << "EMPATE!!" << std::endl;
  }
  return true;
}*/

void Reversi::match(Player* player1, Player* player2) {
  int row, col;
  std::string currentPlayer = player1->getNickName();
  std::string outerPlayer = player2->getNickName();

  printBoard();
  piecesCounter();

  while(1) {
    std::cout << "Vez de " << currentPlayer << " jogar(" << _turn << "):" << std::endl << std::endl;
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

    if(
      row < 0 || 
      row > _defaultRows - 1 || 
      col < 0 || 
      col > _defaultCols - 1
    ) {
      std::cout << "ERRO: jogada inválida" << std::endl;   //jogar em lugar ocupado
      continue;
    }

    if(_board[row][col] != " ") {
      std::cout << "ERRO: jogada inválida" << std::endl;   //jogar em lugar ocupado
      continue;
    }

    if(!thereIsNearby(row, col)) {
      std::cout << "ERRO: jogada inválida" << std::endl;   //nao tem peça oposta perto
      continue;
    }

    if(!thereIsConnection(row, col)) {
      std::cout << "ERRO: jogada inválida" << std::endl;   //nao tem conexão com outro da mesma peça
      continue;
    }

    makeMove(row, col); //Antigo isPlaying
    
    printBoard();
    piecesCounter();
      
    if(isBoardFull()) {      
      std::string winner;

      if(_xCounter > _oCounter) {
        winner = _turn == "X" ? currentPlayer : outerPlayer;
      } else if(_xCounter < _oCounter) {
        winner = _turn == "O" ? currentPlayer : outerPlayer;
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

    std::string aux = _turn;
    _turn = _watching;
    _watching = aux;

    aux = currentPlayer;
    currentPlayer = outerPlayer;
    outerPlayer = aux;
      
    if(!isAnyPossiblePlay()) {
      std::cout << std::endl << "Nao há jogadas possíveis para o(a) jogador(a) " << currentPlayer << std::endl;
      std::string aux = _turn;
      _turn = _watching;
      _watching = aux;

      aux = currentPlayer;
      currentPlayer = outerPlayer;
      outerPlayer = aux;
    }

  }
}