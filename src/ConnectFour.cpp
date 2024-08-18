#include "ConnectFour.hpp"
#include <iostream>
#include <limits>

/**
 * @brief Construtor da classe ConnectFour.
 * @param rows Número de linhas do tabuleiro.
 * @param cols Número de colunas do tabuleiro.
 */
ConnectFour::ConnectFour(int rows, int cols) : Game(rows, cols){}

/**
 * @brief Verifica se a jogada é válida.
 * @param col A coluna onde a jogada será feita.
 * @return Verdadeiro se a jogada é válida, falso caso contrário.
 */
bool ConnectFour::isValidMove(int col) const {
	if (col < 1 || col > _defaultCols) return false;
	return _board[0][col - 1] == " ";
}

/**
 * @brief Faz uma jogada, colocando uma peça na coluna especificada.
 * @param col A coluna onde a peça será colocada.
 * @return Verdadeiro se a jogada for bem-sucedida, falso caso contrário.
 */
bool ConnectFour::makeMove(int col, std::string currentPiece) {
	if (!isValidMove(col)) return false;
	col -= 1; // Ajustar para índice de base 0

	for (int row = _defaultRows - 1; row >= 0; --row) {
		if (_board[row][col] == " ") {
			_board[row][col] = currentPiece;
			return true;
		}
	}
	return false;
}

/**
 * @brief Verifica se o jogador atual ganhou.
 * @return Verdadeiro se o jogador ganhou, falso caso contrário.
 */
bool ConnectFour::checkWin(std::string currentPiece) const {
	return checkHorizontal(currentPiece) || checkVertical(currentPiece) || checkDiagonal(currentPiece);
}

/**
 * @brief Verifica se há uma linha horizontal de quatro peças do jogador atual.
 * @return Verdadeiro se houver uma linha horizontal de quatro peças, falso caso contrário.
 */
bool ConnectFour::checkHorizontal(std::string currentPiece) const {
	for (int row = 0; row < _defaultRows; ++row) {
		for (int col = 0; col <= _defaultCols - 4; ++col) {
			if (_board[row][col] == currentPiece && _board[row][col + 1] == currentPiece &&
				_board[row][col + 2] == currentPiece && _board[row][col + 3] == currentPiece) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief Verifica se há uma linha vertical de quatro peças do jogador atual.
 * @return Verdadeiro se houver uma linha vertical de quatro peças, falso caso contrário.
 */
bool ConnectFour::checkVertical(std::string currentPiece) const {
	for (int col = 0; col < _defaultCols; ++col) {
		for (int row = 0; row <= _defaultRows - 4; ++row) {
			if (_board[row][col] == currentPiece && _board[row + 1][col] == currentPiece &&
				_board[row + 2][col] == currentPiece && _board[row + 3][col] == currentPiece) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief Verifica se há uma linha diagonal de quatro peças do jogador atual.
 * @return Verdadeiro se houver uma linha diagonal de quatro peças, falso caso contrário.
 */
bool ConnectFour::checkDiagonal(std::string currentPiece) const {
	for (int row = 0; row <= _defaultRows - 4; ++row) {
		for (int col = 0; col <= _defaultCols - 4; ++col) {
			if (_board[row][col] == currentPiece && _board[row + 1][col + 1] == currentPiece &&
				_board[row + 2][col + 2] == currentPiece && _board[row + 3][col + 3] == currentPiece) {
				return true;
			}
		}
	}
	for (int row = 3; row < _defaultRows; ++row) {
		for (int col = 0; col <= _defaultCols - 4; ++col) {
			if (_board[row][col] == currentPiece && _board[row - 1][col + 1] == currentPiece &&
				_board[row - 2][col + 2] == currentPiece && _board[row - 3][col + 3] == currentPiece) {
				return true;
			}
		}
	}
	return false;
}

/**
 * @brief Imprime o estado atual do tabuleiro.
 */
void ConnectFour::printBoard() const {
	std::cout << "  ";
	for (int col = 1; col <= _defaultCols; ++col) {
		if (col > 1) {
			std::cout << " " << col << "  ";
		} else {
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

/**
 * @brief Conta o número de possíveis formas de ganhar para o jogador atual.
 * @return Número de possíveis formas de ganhar.
 */
void ConnectFour::countPossibleWins(std::string currentPiece) const {	
	int count = 0;

	// Horizontal
	for (int row = 0; row < _defaultRows; ++row) {
		for (int col = 0; col <= _defaultCols - 4; ++col) {
			int emptyCount = 0;
			int pieceCount = 0;

			for (int i = 0; i < 4; ++i) {
				if (_board[row][col + i] == currentPiece) {
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

	// Vertical
	for (int col = 0; col < _defaultCols; ++col) {
		for (int row = 0; row <= _defaultRows - 4; ++row) {
			int emptyCount = 0;
			int pieceCount = 0;

			for (int i = 0; i < 4; ++i) {
				if (_board[row + i][col] == currentPiece) {
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

	// Diagonal
	for (int row = 0; row <= _defaultRows - 4; ++row) {
		for (int col = 0; col <= _defaultCols - 4; ++col) {
			int emptyCount = 0;
			int pieceCount = 0;

			for (int i = 0; i < 4; ++i) {
				if (_board[row + i][col + i] == currentPiece) {
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

	// Diagonal inversa
	for (int row = 3; row < _defaultRows; ++row) {
		for (int col = 0; col <= _defaultCols - 4; ++col) {
			int emptyCount = 0;
			int pieceCount = 0;

			for (int i = 0; i < 4; ++i) {
				if (_board[row - i][col + i] == currentPiece) {
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

	std::cout << std::endl;
	std::cout << "Possíveis formas de ganhar para " << currentPiece << ": " << count << '\n';
}

/**
 * @brief Executa uma partida entre dois jogadores.
 * @param player1 Ponteiro para o primeiro jogador.
 * @param player2 Ponteiro para o segundo jogador.
 */
void ConnectFour::match(Player* player1, Player* player2) {

	std::string nickNamePlayer1 = player1->getNickName();
	std::string nickNamePlayer2 = player2->getNickName();

	std::string currentPlayer = nickNamePlayer1;
	std::string currentPiece = "X";

	while (true) {
		countPossibleWins(currentPiece);
		printBoard();

		std::cout << "Turno de " << currentPlayer << " (" << currentPiece << "): ";
		int input;

		try{
			if(!(std::cin >> input) || input < 1 || input > _defaultCols) {
				throw std::out_of_range("Posição fora dos limites do tabuleiro!");
			}
			if(!makeMove(input, currentPiece)) {
				throw std::invalid_argument("Coluna cheia. Tente novamente!");
			}
		}catch (const std::out_of_range& e) {
			std::cout << "ERRO:" << e.what() << std::endl;
			continue;
		}catch (const std::invalid_argument& e) {
			std::cout << "ERRO:" << e.what() << std::endl;
			continue;
		}

		if (checkWin(currentPiece)) {
			countPossibleWins(currentPiece);
			printBoard();
			std::cout << "Parabéns " << currentPlayer << "! Você venceu!\n";

			if (currentPlayer == nickNamePlayer1) {
				player1->setVictories("connectFour");
				player2->setDefeats("connectFour");
			} else {
				player1->setDefeats("connectFour");
				player2->setVictories("connectFour");
			}

			std::cout << std::endl;
			break;
		}

		if (isBoardFull()) {
			printBoard();
			std::cout << "O jogo terminou em empate!\n";
			break;
		}

		currentPlayer = (currentPlayer == nickNamePlayer1) ? nickNamePlayer2 : nickNamePlayer1;
		currentPiece = (currentPiece == "X") ? "O" : "X";
	}
}
