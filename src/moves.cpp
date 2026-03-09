//
// Created by kevin on 3/8/2026.
//

#include "moves.h"

bool is_valid_move(const std::string board[], int position) {
    if (position < 1 || position > 9) {
        return false;
    }

    return board[position - 1] == std::to_string(position);
}


bool make_move(std::string board[], int position, const std::string& player_mark) {
    if (!is_valid_move(board, position)) {
        return false;
    }

    board[position - 1] = player_mark;
    return true;
}