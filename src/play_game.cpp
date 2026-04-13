#include "play_game.hpp"
#include "print_board.h"
#include "moves.h"
#include "result.h"
#include <vector>
#include <iostream>

using namespace std;

void playGame(bool vsComputer, bool computerFirst) {
    vector<char> board(9, ' ');
    char human = 'X';
    char computer = 'O';

    bool humanTurn = !(vsComputer && computerFirst);

    while (true) {
        printBoard(board);

        if (!vsComputer) {
            cout << (humanTurn ? "Player X turn:\n" : "Player O turn:\n");
            int move = getHumanMove(board);
            board[move] = humanTurn ? 'X' : 'O';
        } else {
            if (humanTurn) {
                cout << "Human turn:\n";
                int move = getHumanMove(board);
                board[move] = human;
            } else {
                cout << "Computer turn:\n";
                int move = getComputerMove(board);
                board[move] = computer;
            }
        }

        char result = checkWinner(board);
        if (result != ' ') {
            printBoard(board);
            if (result == 'T')
                cout << "It's a tie!\n";
            else
                cout << result << " wins!\n";
            break;
        }

        humanTurn = !humanTurn;
    }
}