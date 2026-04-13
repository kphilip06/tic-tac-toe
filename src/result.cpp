#include "result.h"

char checkWinner(const std::vector<char>& b) {
    int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (auto& w : wins) {
        if (b[w[0]] != ' ' && b[w[0]] == b[w[1]] && b[w[1]] == b[w[2]])
            return b[w[0]];
    }

    for (char c : b)
        if (c == ' ')
            return ' ';

    return 'T';
}