#include "ConnectFour.hpp"
#include <iostream>
#include <limits>

bool isValidInput(int input, int min, int max) {
    if (std::cin.fail()) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    } 
    return std::cin.good() && input >= min && input <= max;
}

int getBoardSizeChoice() {
    int choice;
    std::cout << "Escolha o tamanho do Tabuleiro:\n";
    std::cout << "1. 6x6\n";
    std::cout << "2. 6x7\n";
    std::cout << "3. 6x8\n";
    std::cout << "Digite o número da opção desejada: ";
    std::cin >> choice;

    while (!isValidInput(choice, 1, 3)) {
        std::cin.clear();
        std::cout << "ERRO: Entrada inválida. Digite um número de 1 a 3.\n";
        std::cout << "Escolha o tamanho do grid:\n";
        std::cout << "1. 6x6\n";
        std::cout << "2. 6x7\n";
        std::cout << "3. 6x8\n";
        std::cout << "Digite o número da opção desejada: ";
        std::cin >> choice;
    }

    return choice;
}

int main() {
    int choice = getBoardSizeChoice();
    int rows, cols;

    switch (choice) {
        case 1:
            rows = 6;
            cols = 6;
            break;
        case 2:
            rows = 6;
            cols = 7;
            break;
        case 3:
            rows = 6;
            cols = 8;
            break;
        default:
            std::cerr << "ERRO: Escolha de tamanho inválida.\n";
            return 1;
    }

    ConnectFour game(rows, cols);

    std::string currentPlayer = "João";
    char currentPiece = 'X';

    while (true) {
        game.printBoard(currentPiece);

        std::cout << "Turno de " << currentPlayer << " (" << currentPiece << "): ";
        int col;
        std::cin >> col;

        if (!isValidInput(col, 1, cols) || !game.makeMove(col, currentPiece)) {
            std::cout << "ERRO: Jogada inválida ou coluna cheia\n";
            std::cin.clear();
            continue;
        }

        if (game.checkWin(currentPiece)) {
            game.printBoard(currentPiece);
            std::cout << "Parabéns " << currentPlayer << "! Você venceu!\n";
            break;
        }

        if (game.isBoardFull()) {
            game.printBoard(currentPiece);
            std::cout << "O jogo terminou em empate!\n";
            break;
        }

        currentPlayer = (currentPlayer == "João") ? "Maria" : "João";
        currentPiece = (currentPiece == 'X') ? 'O' : 'X';
    }

    return 0;
}
