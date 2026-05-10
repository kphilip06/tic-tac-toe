#ifndef GAME_MOVES_H
#define GAME_MOVES_H

#include <vector>

int generateTrap();
int getComputerMove(const std::vector<char>& board);
bool processMove(std::vector<char>& board, int move, char marker, int trapCell);

#endif