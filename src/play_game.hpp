#include <string>

void print_board(const std::string board[]);
bool is_valid_move(const std::string board[], int position);
bool make_move(std::string board[], int position, const std::string& player_mark);
bool has_winner(const std::string board[]);
bool is_draw(const std::string board[]);
void reset_board(std::string board[]);
int get_player_move(const std::string board[], const std::string& player_mark);
bool ask_to_play_again();
void play_game();
