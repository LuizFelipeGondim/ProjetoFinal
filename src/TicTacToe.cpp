#include "TicTacToe.hpp"
#include <iostream>

/**
 * @brief Construtor da classe TicTacToe.
 */
TicTacToe::TicTacToe(int rows, int cols) : Game(rows, cols) {}

/**
 * @brief Verifica se há um vencedor no jogo.
 * @return Verdadeiro se houver um vencedor, falso caso contrário.
 */
bool TicTacToe::checkWin() const {
  // Verifica as linhas
  for (const auto& row : _board) {
    if (row[0] != " " && row[0] == row[1] && row[1] == row[2]) {
      return true;
    }
  }

  // Verifica as colunas
  for (int col = 0; col < 3; ++col) {
    if (_board[0][col] != " " && _board[0][col] == _board[1][col] && _board[1][col] == _board[2][col]) {
      return true;
    }
  }

  // Verifica as diagonais
  if (_board[0][0] != " " && _board[0][0] == _board[1][1] && _board[1][1] == _board[2][2]) {
    return true;
  }
  if (_board[0][2] != " " && _board[0][2] == _board[1][1] && _board[1][1] == _board[2][0]) {
    return true;
  }

  return false;
}

/**
 * @brief Executa uma jogada no tabuleiro.
 * @param row Linha da jogada.
 * @param col Coluna da jogada.
 * @param symbol Símbolo do jogador.
 * @return Verdadeiro se a jogada for válida, falso caso contrário.
 */
bool TicTacToe::makeMove(int row, int col, const std::string& symbol) {
  if (row >= 0 && row < 3 && col >= 0 && col < 3 && _board[row][col] == " ") {
    _board[row][col] = symbol;
    return true;
  }
  return false;
}

/**
 * @brief Executa uma partida de Tic Tac Toe entre dois jogadores.
 * @param player1 Ponteiro para o primeiro jogador.
 * @param player2 Ponteiro para o segundo jogador.
 */
void TicTacToe::match(Player* player1, Player* player2) {

  std::string nickNamePlayer1 = player1->getNickName();
  std::string nickNamePlayer2 = player2->getNickName();

  std::string currentPlayer = nickNamePlayer1;
  std::string currentPiece = "X";  // Definir símbolo inicial

  while (!isBoardFull() && !checkWin()) {
    printBoard();
    int row, col;

    std::cout << std::endl;
    std::cout << currentPlayer << " (" << currentPiece << "), faça sua jogada (linha e coluna): ";
    std::cin >> row >> col;
    --row; // Ajusta para índice baseado em 0
    --col; // Ajusta para índice baseado em 0

    if (makeMove(row, col, currentPiece)) {
      if (checkWin()) {
        printBoard();

        std::cout << std::endl;
        std::cout << currentPlayer << " venceu!" << std::endl;
        std::cout << std::endl;

        if (currentPlayer == nickNamePlayer1) {
          player1->setVictories("ticTacToe");
          player2->setDefeats("ticTacToe");
        } else {
          player1->setDefeats("ticTacToe");
          player2->setVictories("ticTacToe");
        }
        return;
      }
      // Alterna o jogador e o símbolo
      currentPlayer = (currentPlayer == nickNamePlayer1) ? nickNamePlayer2 : nickNamePlayer1;
      currentPiece = (currentPiece == "X") ? "O" : "X";
    } else {
      std::cout << "Movimento inválido! Tente novamente." << std::endl;
    }
  }

  printBoard();
  if (isBoardFull() && !checkWin()) {
    std::cout << "O jogo terminou em empate!" << std::endl;
    std::cout << std::endl;
  }

}
