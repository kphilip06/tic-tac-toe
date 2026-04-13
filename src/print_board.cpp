
#include "print_board.h"
#include <iostream>

using namespace std;

void printBoard(const vector<char>& b) {
    cout << "\n";
    cout << " " << b[0] << " | " << b[1] << " | " << b[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << b[3] << " | " << b[4] << " | " << b[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << b[6] << " | " << b[7] << " | " << b[8] << "\n\n";
}