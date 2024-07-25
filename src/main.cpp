#include "ConnectFour.hpp"
#include <iostream>
#include <limits>

bool isValidInput(int input, int max) {
    return std::cin.good() && input >= 0 && input < max;
}

int main() {
    int rows, cols;
    std::cout << "Escolha o tamanho do grid (linhas e colunas): ";
    std::cin >> rows >> cols;

    ConnectFour game(rows, cols);

    std::string currentPlayer = "João";
    char currentPiece = 'X';

    while (true) {
        game.printBoard(currentPiece);

        std::cout << "Turno de " << currentPlayer << " (" << currentPiece << "): ";
        int col;
        std::cin >> col;

        if (!isValidInput(col, cols) || !game.makeMove(col, currentPiece)) {
            std::cout << "ERRO: Jogada inválida ou coluna cheia\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (game.checkWin(currentPiece)) {
            game.printBoard(currentPiece);
            std::cout << "Parabéns " << currentPlayer << "! Você venceu!\n";
            break;
        }

        // Alternar jogador
        if (currentPlayer == "João") {
            currentPlayer = "Maria";
            currentPiece = 'O';
        } else {
            currentPlayer = "João";
            currentPiece = 'X';
        }
    }

    return 0;
}
