//
// Created by kevin on 3/8/2026.
//

#include "moves.h"
#include <iostream>
#include <limits>

using namespace std;

int getHumanMove(const vector<char>& board) {
    int move;

    while (true) {
        cout << "Enter a position (1-9): ";

        if (!(cin >> move)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        move -= 1;

        if (move < 0 || move > 8) {
            cout << "Out of range. Try again.\n";
            continue;
        }

        if (board[move] != ' ') {
            cout << "Spot taken. Try again.\n";
            continue;
        }

        return move;
    }
}

int getComputerMove(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            return i;
    }
    return -1;
}
