#include "game_moves.h"
#include <random>
#include <ctime>
#include <iostream>

int generateTrap() {
    static std::mt19937 rng(time(0));
    std::uniform_int_distribution<int> dist(0, 8);
    return dist(rng);
}

int getComputerMove(const std::vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] != 'X' && board[i] != 'O') return i;
    }
    return -1;
}

bool processMove(std::vector<char>& board, int move, char marker, int trapCell) {
    if (move < 0 || move > 8 || board[move] == 'X' || board[move] == 'O') return false;

    if (trapCell != -1 && move == trapCell) {
        std::cout << "!! TRAP TRIGGERED !! Turn lost.\n";
        return true; // Move "happened" but board didn't change
    }

    board[move] = marker;
    return true;
}