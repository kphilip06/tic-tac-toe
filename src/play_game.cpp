#include "player_prompts.h"
#include "moves.h"
#include "result.h"
#include "reset.h"
#include "print_board.h"
#include <iostream>
#include <string>

void play_game() {
    std::string board[9];
    bool play_again = true;

    while (play_again) {
        reset_board(board);
        std::string current_player = "X";

        print_board(board);

        while (true) {
            int position = get_player_move(board, current_player);
            make_move(board, position, current_player);

            print_board(board);

            if (has_winner(board)) {
                std::cout << "Player " << current_player << " wins!" << std::endl;
                break;
            }

            if (is_draw(board)) {
                std::cout << "The game is a draw!" << std::endl;
                break;
            }

            current_player = (current_player == "X") ? "O" : "X";
        }

        play_again = ask_to_play_again();
    }

    std::cout << "Thanks for playing Tic-Tac-Toe!" << std::endl;
}
