#include "board_logic.h"
#include <iostream>
#include <vector>

void resetBoard(std::vector<char>& board) {
    for (int i = 0; i < 9; ++i) board[i] = (i + 1) + '0';
}

void displayBoard(const std::vector<char>& board) {
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << " \n";
        if (i < 6) std::cout << "-----------\n";
    }
}

bool checkWin(const std::vector<char>& board) {
    const int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for (auto& w : wins) {
        if (board[w[0]] == board[w[1]] && board[w[1]] == board[w[2]]) return true;
    }
    return false;
}

bool checkDraw(const std::vector<char>& board, int trapCell) {
    for (int i = 0; i < 9; ++i) {
        if (i == trapCell) continue; // Acceptance Criteria: Ignore trap cell for draw
        if (board[i] != 'X' && board[i] != 'O') return false;
    }
    return true;
}