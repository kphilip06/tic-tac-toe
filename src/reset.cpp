//
// Created by kevin on 3/8/2026.
//
#include <string>
#include "reset.h"

void reset_board(std::string board[]) {
    for (int i = 0; i < 9; i++) {
        board[i] = std::to_string(i + 1);
    }
}