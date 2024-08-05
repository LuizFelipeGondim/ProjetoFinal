#include "Game.hpp"
#include "Reversi.hpp"
#include <iostream>
#include <limits>
#include <string>

Reversi::Reversi(int rows, int cols) : Game(rows+1, 2*cols+2) {
    
  for(int i = 0; i < _defaultCols; i++) {
    if(i == 0 || i % 2 == 1) {
      _board[0][i] = " ";  
    } else {
      _board[0][i] = std::to_string(i/2);
    }
  }

  for(int i = 1; i < _defaultRows; i++) {
    for(int j = 0; j < _defaultCols; j++) {
      if(j == 0){
        _board[i][j] = std::to_string(i);
      }else if(j % 2 == 1){
        _board[i][j] = "|";    
      }else{
        _board[i][j] = " ";
      }  
    }  
  }

  _board[(_defaultRows-1)/2][(_defaultCols-2)/2] = "X";
  _board[(_defaultRows-1)/2 + 1][(_defaultCols-2)/2] = "O";
  _board[(_defaultRows-1)/2][(_defaultCols + 2)/2] = "O";
  _board[(_defaultRows-1)/2 + 1][(_defaultCols + 2)/2] = "X";
}

void Reversi::printBoard() const {
  for(int i = 0; i < _defaultRows; ++i) {
    for(int j = 0; j < _defaultCols; ++j) {
      std::cout << _board[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

bool Reversi::thereIsNearby(int rows, int cols) {
  int maxRows = _defaultRows;
  int maxCols = _defaultCols;

  bool top = (rows - 1 >= 0);
  bool bottom = (rows + 1 < maxRows);
  bool left = (2 * cols - 2 >= 0);
  bool right = (2 * cols + 2 < maxCols);

  if (
    (bottom && _board[rows + 1][2 * cols] == _watching) ||
    (top && _board[rows - 1][2 * cols] == _watching) ||
    (right && _board[rows][2 * cols + 2] == _watching) ||
    (left && _board[rows][2 * cols - 2] == _watching) ||
    (bottom && right && _board[rows + 1][2 * cols + 2] == _watching) ||
    (bottom && left && _board[rows + 1][2 * cols - 2] == _watching) ||
    (top && right && _board[rows - 1][2 * cols + 2] == _watching) ||
    (top && left && _board[rows - 1][2 * cols - 2] == _watching)
  ) {
    return true;
  }

  return false;
}

bool Reversi::thereIsConnection(int rows, int cols) {
  bool playable = false;
  if(!(rows == _defaultRows - 1)) {
    if(_board[rows+1][2*cols] == _watching) {            //Embaixo
      for(int i = rows+1; i < _defaultRows; i++) {
        if(_board[i][2*cols] == _watching){
          continue;
        }
        else if(_board[i][2*cols] == " ") {
          break;
        } 
        else if(_board[i][2*cols] == _turn) {
          playable = true;
          break;
        }
      }
    }
    if(_board[rows+1][2*cols+2] == _watching) {     //Embaixo-Direita
      int i = rows+1;
      int j = 2*cols+2;               
      for(;i < _defaultRows && j < _defaultCols ; i += 1,j += 2) {
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
    if(_board[rows+1][2*cols-2] == _watching) {     //Embaixo-Esquerda
      int i = rows+1;
      int j = 2*cols-2;               
      for(;i < _defaultRows && j >= 0 ; i+=1, j-=2) {
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
  if(!(rows == 1)) {
    if(_board[rows-1][2*cols] == _watching) {       //Em cima
      for(int i = rows-1; i >= 0; i--) {
        if(_board[i][2*cols] == _watching) {
          continue;
        }
        else if(_board[i][2*cols] == " ") {
          break;
        } 
        else if(_board[i][2*cols] == _turn) {
          playable = true;
          break;
        }
      }
    }

    if(_board[rows-1][2*cols+2] == _watching) {     //Em cima-Direita
      int i = rows-1;
      int j = 2*cols+2;               
      for(;i >= 0 && j < _defaultCols ; i-=1, j+=2) {
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
    if(_board[rows-1][2*cols-2] == _watching) {     //Em cima-Esquerda
      int i = rows-1;
      int j = 2*cols-2;               
      for(;i >= 0 && j >= 0 ; i-=1, j-=2) {
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
  if(!(cols == _defaultCols - 2)) {
    if(_board[rows][2*cols+2] == _watching) {       //Direita
      for(int i = 2*cols+2;i < _defaultCols; i+=2) {
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
  if(!(cols == 2)) {
    if(_board[rows][2*cols-2] == _watching) {       //Esquerda
      for(int i = 2*cols-2;i >= 0; i-=2) {
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

void Reversi::isPlaying(int rows,int cols) {
  _board[rows][2*cols] = _turn;
  if(!(rows == _defaultRows - 1)){
    if(_board[rows+1][2*cols] == _watching) {            //Embaixo
      for(int i = rows+1;i < _defaultRows; i++) {
        if(_board[i][2*cols] == _watching) {
          continue;
        }
        else if(_board[i][2*cols] == " ") {
          break;
        } 
        else if(_board[i][2*cols] == _turn) {
          for(int k = rows+1;k <= i; k++) {
            _board[k][2*cols] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows+1][2*cols+2] == _watching) {     //Embaixo-Direita
      int i = rows+1;
      int j = 2*cols+2;               
      for(;i < _defaultRows && j < _defaultCols ; i+=1, j+=2) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          for(int k = rows+1,m = 2*cols+2;k <= i; k++, m+=2) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows+1][2*cols-2] == _watching) {     //Embaixo-Esquerda
      int i = rows+1;
      int j = 2*cols-2;               
      for(;i < _defaultRows && j >= 0 ; i+=1, j-=2) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        }    
        else if(_board[i][j] == _turn) {
          for(int k = rows+1,m = 2*cols-2;k <= i; k++, m-=2) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }
  }
  if(!(rows == 1)) {
    if(_board[rows-1][2*cols] == _watching) {       //Em cima
      for(int i = rows-1;i >= 0; i--){
        if(_board[i][2*cols] == _watching) {
          continue;
        }
        else if(_board[i][2*cols] == " ") {
          break;
        } 
        else if(_board[i][2*cols] == _turn) {
          for(int k = rows-1;k >= i; k--) {
            _board[k][2*cols] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows-1][2*cols+2] == _watching) {     //Em cima-Direita
      int i = rows-1;
      int j = 2*cols+2;               
      for(;i >= 0 && j < _defaultCols ; i-=1, j+=2) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          for(int k = rows-1,m = 2*cols+2; k >= i; k--, m+=2) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }

    if(_board[rows-1][2*cols-2] == _watching) {     //Em cima-Esquerda
      int i = rows-1;
      int j = 2*cols-2;               
      for(;i >= 0 && j >= 0 ; i-=1, j-=2) {
        if(_board[i][j] == _watching) {
          continue;
        }
        else if(_board[i][j] == " ") {
          break;
        } 
        else if(_board[i][j] == _turn) {
          for(int k = rows-1,m = 2*cols-2; k >= i; k--, m-=2) {
            _board[k][m] = _turn;
          }
          break;
        }
      }
    }
  }
  if(!(cols == _defaultCols - 2)) {
    if(_board[rows][2*cols+2] == _watching) {                //Direita
      for(int i = 2*cols+2;i < _defaultCols; i+=2) {
        if(_board[rows][i] == _watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == _turn) {
          for(int k = 2*cols+2;k <= i; k+=2) {
            _board[rows][k] = _turn;
          }
          break;
        }
      }
    }
  }
  if(!(cols == 2)) {
    if(_board[rows][2*cols-2] == _watching) {       //Esquerda
      for(int i = 2*cols-2;i >= 0; i-=2) {
        if(_board[rows][i] == _watching) {
          continue;
        }
        else if(_board[rows][i] == " ") {
          break;
        } 
        else if(_board[rows][i] == _turn) {
          for(int k = 2*cols-2;k >= i; k-=2) {
            _board[rows][k] = _turn;
          }
          break;
        }
      }
    }
  }
}

void Reversi::counter() {
  int auxXCounter = 0;
  int auxOCounter = 0;
  for(int i = 1;i < _defaultRows; i++) {
    for(int j = 2;j < _defaultCols; j+=2) {
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
  std::cout << "|      X = " << _xCounter;         //|  X = 12  |  O = 23  |
  std::cout << "      |      O = " << _oCounter << "      |" << std::endl;
  std::cout << "-------------------------------------" << std::endl;
}

bool Reversi::isBoardFull() const {
  int piece;
  if(_turn == "X") {
    piece = _xCounter;
  } 
  else if(_turn == "O") {
    piece = _oCounter;
  }

  if(piece == 0) {
    return false;
  }

  return true; 
}

bool Reversi::isAnyPossiblePlay() {
  for(int i = 1;i < _defaultRows; i++) {
    for(int j = 2;j < _defaultCols; j+=2) {
      if(_board[i][j] == " ") {
        if(!thereIsNearby(i,(j/2))) {
          continue;
        }
        if(!thereIsConnection(i,(j/2))) {
          continue;
        }
        return true;
      }
    }
  }
  return false;
}

bool Reversi::gameOver() {
  int x = 0;
  int o = 0;
  for(int i = 1;i < _defaultRows; i++) {
    for(int j = 2;j < _defaultCols; j+=2) {
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
}

void Reversi::match(Player* player1, Player* player2) {
  int row, col;
  std::string currentPlayer = player1->getNickName();
  std::string outerPlayer = player2->getNickName();

  printBoard();
  counter();

  while(1) {
    std::cout << "Vez do " << currentPlayer << " jogar:" << std::endl << std::endl;
    std::cin >> row;

    if(std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "ERRO: Entrada inválida." << std::endl;
      continue;
    }

    if(row == -1) {
      std::cout << currentPlayer << " desistiu, vitória do " << outerPlayer << "." << std::endl;

      if (outerPlayer == player1->getNickName()) {
        player1->setVictories("reversi");
        player2->setDefeats("reversi");
      } else {
        player1->setDefeats("reversi");
        player2->setVictories("reversi");
      }

      break;
    }

    std::cin >> col;

    if(std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "ERRO: Entrada inválida." << std::endl;
      continue;
    }

    if(
      row < 1 || 
      row > _defaultRows-1 || 
      col < 1 || 
      col > (_defaultCols-2)/2
    ) {
      std::cout << "ERRO: jogada inválida" << std::endl;   //jogar em lugar ocupado
      continue;
    }

    if(_board[row][2*col] != " ") {
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
      
    isPlaying(row, col);
    
    printBoard();
    counter();

    std::string aux = _turn;
    _turn = _watching;
    _watching = aux;

    aux = currentPlayer;
    currentPlayer = outerPlayer;
    outerPlayer = aux;

    if(!isBoardFull()) {
      std::cout << std::endl << "Jogador " << outerPlayer << " GANHOU !!" << std::endl;

      if (outerPlayer == player1->getNickName()) {
        player1->setVictories("reversi");
        player2->setDefeats("reversi");
      } else {
        player1->setDefeats("reversi");
        player2->setVictories("reversi");
      }

      break;
    }
      
    if(gameOver()) {       
      break;
    }
      
    if(!isAnyPossiblePlay()) {
      std::cout << std::endl << "Nao há jogadas possíveis para o jogador " << currentPlayer << std::endl;
      std::string aux = _turn;
      _turn = _watching;
      _watching = aux;

      aux = currentPlayer;
      currentPlayer = outerPlayer;
      outerPlayer = aux;
    }

  }
}