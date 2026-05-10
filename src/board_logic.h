#ifndef BOARD_LOGIC_H
#define BOARD_LOGIC_H

#include <string>
#include <vector>


// Now includes min and max bounds
int getValidInt(std::string prompt, int min, int max);
bool askPlayAgain();
int mainMenu();
int trapMenu();
bool checkWin(const std::vector<char>& board);
bool checkDraw(const std::vector<char>& board, int trapCell);
void resetBoard(std::vector<char>& board);
void displayBoard(const std::vector<char>& board);


#endif