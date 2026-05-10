#include "interface.h"
#include <iostream>
#include <algorithm>
#include <string>

int getValidInt(std::string prompt, int min, int max) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Strip whitespace
        input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

        try {
            size_t pos;
            int val = std::stoi(input, &pos);

            // Check if it's a whole number and within the allowed range
            if (pos == input.length() && val >= min && val <= max) {
                return val;
            }
        } catch (...) {}

        std::cout << "Invalid selection. Please enter a number between "
                  << min << " and " << max << ".\n";
    }
}

int mainMenu() {
    return getValidInt("1. Human vs Human\n2. Human vs Computer\nChoice: ", 1, 2);
}

int trapMenu() {
    return getValidInt("Enable Trap Cell? (1 for Yes, 0 for No): ", 0, 1);
}

bool askPlayAgain() {
    while (true) {
        std::cout << "Play again? (y/n): ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "y" || input == "Y") return true;
        if (input == "n" || input == "N") return false;
        std::cout << "Please enter 'y' or 'n'.\n";
    }
}