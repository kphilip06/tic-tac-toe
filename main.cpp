#include <iostream>
#include <vector>
#include <string>
#include "src/board_logic.h"
#include "src/interface.h"
#include "src/game_moves.h"

int main() {
    std::cout << "======================================\n";
    std::cout << "  WELCOME TO TIC-TAC-TOE: PORTFOLIO   \n";
    std::cout << "======================================\n";

    do {
        // 1. Initialization
        std::vector<char> board(9);
        resetBoard(board);

        // 2. Setup Menus with Range Validation
        int mode = mainMenu(); // Validates 1 or 2

        int trapOn = trapMenu(); // Validates 0 or 1
        int trapCell = (trapOn == 1) ? generateTrap() : -1;

        bool compFirst = false;
        if (mode == 2) {
            int order = getValidInt("Computer goes 1st (1) or 2nd (2)? ", 1, 2);
            compFirst = (order == 1);
        }

        char currentMarker = 'X';
        bool gameOver = false;

        // 3. Main Game Loop
        while (!gameOver) {
            displayBoard(board);
            int moveIndex = -1;

            // Determine whose turn it is
            bool isCompTurn = (mode == 2 &&
                ((compFirst && currentMarker == 'X') || (!compFirst && currentMarker == 'O')));

            if (isCompTurn) {
                std::cout << "Computer (" << currentMarker << ") is thinking...\n";
                moveIndex = getComputerMove(board); // Gets first available 0-8
            } else {
                // getValidInt ensures input is 1-9, stoi handles non-integers/decimals
                int moveInput = getValidInt("Player " + std::string(1, currentMarker) + ", enter move (1-9): ", 1, 9);
                moveIndex = moveInput - 1; // Convert to 0-index
            }

            // 4. Process Move & Turn Validation
            // processMove checks if the cell is already occupied ('X' or 'O')
            if (processMove(board, moveIndex, currentMarker, trapCell)) {

                // 5. Check End Conditions
                if (checkWin(board)) {
                    displayBoard(board);
                    std::cout << "\n*** PLAYER " << currentMarker << " WINS! ***\n";
                    gameOver = true;
                }
                else if (checkDraw(board, trapCell)) {
                    displayBoard(board);
                    std::cout << "\n--- GAME ENDED IN A DRAW ---\n";
                    gameOver = true;
                }
                else {
                    // Switch players only if game isn't over
                    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
                }
            } else {
                // This triggers if the cell was already taken
                std::cout << "\n>> ERROR: That cell is already occupied! Try again. <<\n";
            }
        }

    } while (askPlayAgain()); // Validates y/n

    std::cout << "\nThank you for playing! Returning to system...\n";
    return 0;
}