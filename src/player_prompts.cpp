//
// Created by kevin on 3/8/2026.
//
#include <string>
#include <iostream>
#include "print_board.h"
#include "moves.h"
#include "player_prompts.h"

int get_player_move(const std::string board[], const std::string& player_mark) {
    std::string input;

    while (true) {
        std::cout << "Player " << player_mark << ", enter a cell number (1-9): ";
        std::getline(std::cin, input);

        if (input.empty()) {
            print_board(board);
            std::cout << "Invalid input. Please enter a whole number from 1 to 9." << std::endl;
            continue;
        }

        bool is_number = true;
        for (char ch : input) {
            if (ch < '0' || ch > '9') {
                is_number = false;
                break;
            }
        }

        if (!is_number) {
            print_board(board);
            std::cout << "Invalid input. Please enter a whole number from 1 to 9." << std::endl;
            continue;
        }

        int position = 0;
        try {
            position = std::stoi(input);
        } catch (...) {
            print_board(board);
            std::cout << "Invalid input. Please enter a whole number from 1 to 9." << std::endl;
            continue;
        }

        if (!is_valid_move(board, position)) {
            print_board(board);

            if (position < 1 || position > 9) {
                std::cout << "Invalid move. Please choose a cell from 1 to 9." << std::endl;
            } else {
                std::cout << "Invalid move. That cell is already taken. Try again." << std::endl;
            }

            continue;
        }

        return position;
    }
}

bool ask_to_play_again() {
    std::string input;

    while (true) {
        std::cout << "Would you like to play again? (y/n): ";
        std::getline(std::cin, input);

        if (input == "y" || input == "Y") {
            return true;
        }

        if (input == "n" || input == "N") {
            return false;
        }

        std::cout << "Invalid input. Please enter y or n." << std::endl;
    }
}