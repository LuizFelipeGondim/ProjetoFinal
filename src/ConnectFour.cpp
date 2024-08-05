#include "ConnectFour.hpp"
#include <iostream>
#include <limits>

ConnectFour::ConnectFour(int rows, int cols) : _currentPiece("X"), Game(rows, cols) {}

bool ConnectFour::isValidMove(int col) const {
  if (col < 1 || col > _defaultCols) return false;
  return _board[0][col - 1] == " ";
}

bool ConnectFour::makeMove(int col) {
  if (!isValidMove(col)) return false;
  col -= 1; // Ajustar para índice de base 0
  for (int row = _defaultRows - 1; row >= 0; --row) {
    if (_board[row][col] == " ") {
      _board[row][col] = _currentPiece;
      return true;
    }
  }
  return false;
}

bool ConnectFour::isBoardFull() const {
  for (const auto& row : _board) {
    for (std::string cell : row) {
      if (cell == " ") return false;
    }
  }
  return true;
}

bool ConnectFour::checkWin() const {
  return checkHorizontal() || checkVertical() || checkDiagonal();
}

bool ConnectFour::checkHorizontal() const {
  for (int row = 0; row < _defaultRows; ++row) {
    for (int col = 0; col <= _defaultCols - 4; ++col) {
      if (_board[row][col] == _currentPiece && _board[row][col + 1] == _currentPiece &&
        _board[row][col + 2] == _currentPiece && _board[row][col + 3] == _currentPiece) {
        return true;
      }
    }
  }
  return false;
}

bool ConnectFour::checkVertical() const {
  for (int col = 0; col < _defaultCols; ++col) {
    for (int row = 0; row <= _defaultRows - 4; ++row) {
      if (_board[row][col] == _currentPiece && _board[row + 1][col] == _currentPiece &&
        _board[row + 2][col] == _currentPiece && _board[row + 3][col] == _currentPiece) {
        return true;
      }
    }
  }
  return false;
}

bool ConnectFour::checkDiagonal() const {
  for (int row = 0; row <= _defaultRows - 4; ++row) {
    for (int col = 0; col <= _defaultCols - 4; ++col) {
      if (_board[row][col] == _currentPiece && _board[row + 1][col + 1] == _currentPiece &&
        _board[row + 2][col + 2] == _currentPiece && _board[row + 3][col + 3] == _currentPiece) {
        return true;
      }
    }
  }
  for (int row = 3; row < _defaultRows; ++row) {
    for (int col = 0; col <= _defaultCols - 4; ++col) {
      if (_board[row][col] == _currentPiece && _board[row - 1][col + 1] == _currentPiece &&
        _board[row - 2][col + 2] == _currentPiece && _board[row - 3][col + 3] == _currentPiece) {
        return true;
      }
    }
  }
  return false;
}

void ConnectFour::printBoard() const {
  std::cout << "Possíveis formas de ganhar para " << _currentPiece << ": " << countPossibleWins() << '\n';

  std::cout << "  ";
  for (int col = 1; col <= _defaultCols; ++col) {
    if(col > 1){
      std::cout << " " << col << "  ";
    }
    else{
      std::cout << col << "  ";
    }
    
  }
  std::cout << "\n";

  for (const auto& row : _board) {
    std::cout << "| ";
    for (std::string cell : row) {
      std::cout << cell << " | ";
    }
    std::cout << "\n";
  }
  std::cout << std::string(_defaultCols * 4 + 2, '-') << '\n';
}

int ConnectFour::countPossibleWins() const {
  int count = 0;

  for (int row = 0; row < _defaultRows; ++row) {
    for (int col = 0; col <= _defaultCols - 4; ++col) {
      int emptyCount = 0;
      int pieceCount = 0;

      for (int i = 0; i < 4; ++i) {
        if (_board[row][col + i] == _currentPiece) {
          pieceCount++;
        } else if (_board[row][col + i] == " ") {
          emptyCount++;
        }
      }

      if (pieceCount + emptyCount >= 4 && pieceCount > 0) {
        count++;
      }
    }
  }

  for (int col = 0; col < _defaultCols; ++col) {
    for (int row = 0; row <= _defaultRows - 4; ++row) {
      int emptyCount = 0;
      int pieceCount = 0;

      for (int i = 0; i < 4; ++i) {
        if (_board[row + i][col] == _currentPiece) {
          pieceCount++;
        } else if (_board[row + i][col] == " ") {
          emptyCount++;
        }
      }

      if (pieceCount + emptyCount >= 4 && pieceCount > 0) {
        count++;
      }
    }
  }

  for (int row = 0; row <= _defaultRows - 4; ++row) {
    for (int col = 0; col <= _defaultCols - 4; ++col) {
      int emptyCount = 0;
      int pieceCount = 0;

      for (int i = 0; i < 4; ++i) {
        if (_board[row + i][col + i] == _currentPiece) {
          pieceCount++;
        } else if (_board[row + i][col + i] == " ") {
          emptyCount++;
        }
      }

      if (pieceCount + emptyCount >= 4 && pieceCount > 0) {
        count++;
      }
    }
  }

  for (int row = 3; row < _defaultRows; ++row) {
    for (int col = 0; col <= _defaultCols - 4; ++col) {
      int emptyCount = 0;
      int pieceCount = 0;

      for (int i = 0; i < 4; ++i) {
        if (_board[row - i][col + i] == _currentPiece) {
          pieceCount++;
        } else if (_board[row - i][col + i] == " ") {
          emptyCount++;
        }
      }

      if (pieceCount + emptyCount >= 4 && pieceCount > 0) {
        count++;
      }
    }
  }

  return count;
}

void ConnectFour::match(Player* player1, Player* player2) {

  std::string nickNamePlayer1 = player1->getNickName();
  std::string nickNamePlayer2 = player2->getNickName();

  std::string currentPlayer = nickNamePlayer1;

  while (true) {
    printBoard();

    std::cout << "Turno de " << currentPlayer << " (" << _currentPiece << "): ";
    int input;
    if (!(std::cin >> input) || input < 1 || input > _defaultCols) {
      std::cout << "ERRO: Jogada inválida. Digite um número entre 1 e " << _defaultCols << ".\n";
      std::cin.clear(); // Limpa o estado de erro
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
      continue;
    }

    if (!makeMove(input)) {
      std::cout << "ERRO: Coluna cheia. Tente novamente.\n";
      continue;
    }

    if (checkWin()) {
      printBoard();
      std::cout << "Parabéns " << currentPlayer << "! Você venceu!\n";
      
      if (currentPlayer == nickNamePlayer1) {
        player1->setVictories("connectFour");
        player2->setDefeats("connectFour");
      } else {
        player1->setDefeats("connectFour");
        player2->setVictories("connectFour");
      }
      break;
    }

    if (isBoardFull()) {
      printBoard();
      std::cout << "O jogo terminou em empate!\n";
      break;
    }

    currentPlayer = (currentPlayer == nickNamePlayer1) ? nickNamePlayer2 : nickNamePlayer1;
    _currentPiece = (_currentPiece == "X") ? "O" : "X";
  }
}
