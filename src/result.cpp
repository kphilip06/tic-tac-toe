#include "moves.h"
#include <string>
#include "result.h"


bool has_winner(const std::string board[]) {
    const int winning_lines[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (const auto& line : winning_lines) {
        const std::string& first = board[line[0]];
        const std::string& second = board[line[1]];
        const std::string& third = board[line[2]];

        if (first == second && second == third) {
            return true;
        }
    }

    return false;
}

bool is_draw(const std::string board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == std::to_string(i + 1)) {
            return false;
        }
    }

    return !has_winner(board);
}