#include "TicTacToe.h"

#include <iostream>
#include <sstream>
#include <string>

TicTacToe::TicTacToe() : theBoard{}, currentPlayer('X') {}

void TicTacToe::displayBoard() {
    std::cout << "\n  1 2 3\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << row + 1 << ' ';
        for (int col = 0; col < 3; ++col) {
            std::cout << (theBoard[row][col] == '\0' ? ' ' : theBoard[row][col]);
            if (col < 2) {
                std::cout << '|';
            }
        }
        std::cout << '\n';
        if (row < 2) {
            std::cout << "  -----\n";
        }
    }
    std::cout << '\n';
}

bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || theBoard[row][col] != '\0') {
        return false;
    }

    theBoard[row][col] = currentPlayer;
    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
}

bool TicTacToe::checkWin() {
    for (int index = 0; index < 3; ++index) {
        if (theBoard[index][0] == currentPlayer &&
            theBoard[index][1] == currentPlayer &&
            theBoard[index][2] == currentPlayer) {
            return true;
        }
        if (theBoard[0][index] == currentPlayer &&
            theBoard[1][index] == currentPlayer &&
            theBoard[2][index] == currentPlayer) {
            return true;
        }
    }

    return (theBoard[0][0] == currentPlayer &&
            theBoard[1][1] == currentPlayer &&
            theBoard[2][2] == currentPlayer) ||
           (theBoard[0][2] == currentPlayer &&
            theBoard[1][1] == currentPlayer &&
            theBoard[2][0] == currentPlayer);
}

bool TicTacToe::checkTie() {
    for (const auto& row : theBoard) {
        for (char cell : row) {
            if (cell == '\0') {
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::play() {
    std::cout << "Tic-Tac-Toe\n";
    const auto readCoordinate = [](const char* prompt, int& coordinate) {
        std::string input;
        while (true) {
            std::cout << prompt;
            if (!std::getline(std::cin, input)) {
                std::cout << "\nGame ended.\n";
                return false;
            }

            std::istringstream parser(input);
            int value;
            char extra;
            if ((parser >> value) && !(parser >> extra) && value >= 1 && value <= 3) {
                coordinate = value;
                return true;
            }

            std::cout << "Invalid input. Enter a single number from 1 to 3.\n";
        }
    };

    while (true) {
        displayBoard();
        std::cout << "Player " << currentPlayer << "\n";

        int row;
        int col;
        if (!readCoordinate("Enter row (1-3): ", row) ||
            !readCoordinate("Enter column (1-3): ", col)) {
            return;
        }

        if (!makeMove(row - 1, col - 1)) {
            std::cout << "That square is already occupied. Choose another square.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            return;
        }
        if (checkTie()) {
            displayBoard();
            std::cout << "It's a tie!\n";
            return;
        }

        switchPlayer();
    }
}