#include "src/menu.hpp"
#include "src/play_game.hpp"

int main() {
    int choice = mainMenu();

    if (choice == 1) {
        playGame(false, false);
    } else {
        int order = computerOrderMenu();
        playGame(true, order == 1);
    }

    return 0;
}