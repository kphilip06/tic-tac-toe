#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "../src/board_logic.h"
#include "../src/game_moves.h"


TEST_CASE("Board Initialization", "[core]") {
    std::vector<char> board(9);
    resetBoard(board);

    SECTION("Board should be initialized with numbers 1-9") {
        for (int i = 0; i < 9; ++i) {
            REQUIRE(board[i] == (i + 1) + '0');
        }
    }
}

TEST_CASE("Win Condition Logic", "[logic]") {
    std::vector<char> board = {'X', 'X', 'X', '4', '5', '6', '7', '8', '9'};

    SECTION("Horizontal win detection") {
        REQUIRE(checkWin(board) == true);
    }

    SECTION("No win on mixed row") {
        board = {'X', 'O', 'X', '4', '5', '6', '7', '8', '9'};
        REQUIRE(checkWin(board) == false);
    }

    SECTION("Diagonal win detection") {
        board = {'O', '2', '3', '4', 'O', '6', '7', '8', 'O'};
        REQUIRE(checkWin(board) == true);
    }
}

TEST_CASE("Draw Condition with Trap Cell", "[logic]") {
    // Board is full except for position 8
    std::vector<char> board = {'X', 'O', 'X', 'X', 'O', 'O', 'O', 'X', '9'};

    SECTION("Not a draw if a normal cell is empty") {
        REQUIRE(checkDraw(board, -1) == false);
    }

    SECTION("Is a draw if the only empty cell is the trap cell") {
        // Acceptance Criteria: Draw means every cell filled WITHOUT a winner,
        // not including the trap cell.
        REQUIRE(checkDraw(board, 8) == true);
    }
}

TEST_CASE("Move Processing and Traps", "[moves]") {
    std::vector<char> board(9);
    resetBoard(board);
    int trap = 4; // Center is the trap

    SECTION("Triggering a trap does not change the board") {
        char originalValue = board[4];
        bool result = processMove(board, 4, 'X', trap);

        REQUIRE(result == true); // The move was "processed"
        REQUIRE(board[4] == originalValue); // But the marker was not placed
    }

    SECTION("Valid non-trap move updates board") {
        processMove(board, 0, 'X', trap);
        REQUIRE(board[0] == 'X');
    }

    SECTION("Cannot move to an occupied cell") {
        board[1] = 'O';
        bool result = processMove(board, 1, 'X', trap);
        REQUIRE(result == false);
    }
}

TEST_CASE("Computer AI Behavior", "[ai]") {
    std::vector<char> board = {'X', 'O', 'X', '4', '5', '6', '7', '8', '9'};

    SECTION("Computer picks the first available spot") {
        // Spots 0, 1, 2 are taken. 3 (which is '4') is the first free.
        REQUIRE(getComputerMove(board) == 3);
    }
}
