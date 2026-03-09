#include <catch2/catch_test_macros.hpp>

#include "../src/play_game.hpp"

TEST_CASE("reset_board fills the board with positions 1 through 9") {
    std::string board[9] = {"X", "O", "X", "O", "X", "O", "X", "O", "X"};

    reset_board(board);

    REQUIRE(board[0] == "1");
    REQUIRE(board[1] == "2");
    REQUIRE(board[2] == "3");
    REQUIRE(board[3] == "4");
    REQUIRE(board[4] == "5");
    REQUIRE(board[5] == "6");
    REQUIRE(board[6] == "7");
    REQUIRE(board[7] == "8");
    REQUIRE(board[8] == "9");
}

TEST_CASE("is_valid_move returns true for an open cell in range") {
    std::string board[9];
    reset_board(board);

    REQUIRE(is_valid_move(board, 1));
    REQUIRE(is_valid_move(board, 5));
    REQUIRE(is_valid_move(board, 9));
}

TEST_CASE("is_valid_move returns false for out of range positions") {
    std::string board[9];
    reset_board(board);

    REQUIRE_FALSE(is_valid_move(board, 0));
    REQUIRE_FALSE(is_valid_move(board, -1));
    REQUIRE_FALSE(is_valid_move(board, 10));
}

TEST_CASE("is_valid_move returns false for a taken cell") {
    std::string board[9];
    reset_board(board);
    board[4] = "X";

    REQUIRE_FALSE(is_valid_move(board, 5));
}

TEST_CASE("make_move places a mark on a valid move") {
    std::string board[9];
    reset_board(board);

    bool move_result = make_move(board, 5, "X");

    REQUIRE(move_result);
    REQUIRE(board[4] == "X");
}

TEST_CASE("make_move returns false and does not change board on invalid move") {
    std::string board[9];
    reset_board(board);
    board[0] = "X";

    bool move_result = make_move(board, 1, "O");

    REQUIRE_FALSE(move_result);
    REQUIRE(board[0] == "X");
}

TEST_CASE("has_winner detects a horizontal win") {
    std::string board[9] = {
        "X", "X", "X",
        "4", "5", "6",
        "7", "8", "9"
    };

    REQUIRE(has_winner(board));
}

TEST_CASE("has_winner detects a vertical win") {
    std::string board[9] = {
        "O", "2", "3",
        "O", "5", "6",
        "O", "8", "9"
    };

    REQUIRE(has_winner(board));
}

TEST_CASE("has_winner detects a diagonal win") {
    std::string board[9] = {
        "X", "2", "3",
        "4", "X", "6",
        "7", "8", "X"
    };

    REQUIRE(has_winner(board));
}

TEST_CASE("has_winner returns false when there is no winner") {
    std::string board[9] = {
        "X", "O", "X",
        "X", "O", "O",
        "O", "X", "9"
    };

    REQUIRE_FALSE(has_winner(board));
}

TEST_CASE("is_draw returns true for a full board with no winner") {
    std::string board[9] = {
        "X", "O", "X",
        "X", "O", "O",
        "O", "X", "X"
    };

    REQUIRE(is_draw(board));
}

TEST_CASE("is_draw returns false when spaces remain") {
    std::string board[9] = {
        "X", "O", "X",
        "4", "O", "O",
        "O", "X", "X"
    };

    REQUIRE_FALSE(is_draw(board));
}

TEST_CASE("is_draw returns false when there is a winner") {
    std::string board[9] = {
        "X", "X", "X",
        "O", "O", "6",
        "7", "8", "9"
    };

    REQUIRE_FALSE(is_draw(board));
}
