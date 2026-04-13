//
// Created by kevin on 4/12/2026.
//
#include "menu.hpp"
#include <iostream>
#include <limits>

using namespace std;

int mainMenu() {
    int choice;
    cout << "1. Play vs Human\n";
    cout << "2. Play vs Computer\n";

    while (true) {
        cout << "Choose: ";
        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 1 || choice == 2)
            return choice;

        cout << "Invalid choice.\n";
    }
}

int computerOrderMenu() {
    int choice;
    cout << "1. Computer goes first\n";
    cout << "2. Computer goes second\n";

    while (true) {
        cout << "Choose: ";
        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 1 || choice == 2)
            return choice;

        cout << "Invalid choice.\n";
    }
}