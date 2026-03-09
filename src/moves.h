#pragma once
#include <string>

bool is_valid_move(const std::string board[], int position);
bool make_move(std::string board[], int position, const std::string& player_mark);