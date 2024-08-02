#include "ConnectFour.hpp"
#include <iostream>
#include <string>

bool isNumber(const std::string& str) {
    for (char c : str) {
        if (c < '0' || c > '8') { 
            return false;
        }
    }
    return !str.empty(); 
}

bool isValidInput(const std::string& input, int min, int max) {
    if (!isNumber(input)) {
        return false;
    }
    int value = std::stoi(input);
    return value >= min && value <= max;
}

int getBoardSizeChoice() {
    std::string choice;
    std::cout << "Escolha o tamanho do Tabuleiro:\n";
    std::cout << "1. 6x6\n";
    std::cout << "2. 6x7\n";
    std::cout << "3. 6x8\n";
    std::cout << "Digite o número da opção desejada: ";
    std::getline(std::cin, choice);

    while (!isValidInput(choice, 1, 3)) {
        std::cout << "ERRO: Entrada inválida. Digite um número de 1 a 3.\n";
        std::cout << "Escolha o tamanho do grid:\n";
        std::cout << "1. 6x6\n";
        std::cout << "2. 6x7\n";
        std::cout << "3. 6x8\n";
        std::cout << "Digite o número da opção desejada: ";
        std::getline(std::cin, choice);
    }

    return std::stoi(choice);
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
        std::string input;
        std::getline(std::cin, input);

        if (!isValidInput(input, 1, cols) || !game.makeMove(std::stoi(input), currentPiece)) {
            std::cout << "ERRO: Jogada inválida ou coluna cheia\n";
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
