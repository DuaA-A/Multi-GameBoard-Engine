#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "genericBoardGame.h"

using namespace std;

FourInARowPlayer::FourInARowPlayer(int order, char symbol) : Player(order, symbol) {
    // Optionally, you can customize player initialization for Four-In-A-Row
}

FourInARowBoard::FourInARowBoard() {
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}

FourInARowComputerPlayer::FourInARowComputerPlayer(char symbol) : RandomPlayer(symbol, 7) {
    // Optionally, you can customize computer player initialization for Four-In-A-Row
}


bool FourInARowBoard::update_board(int x, int y, char mark) {
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == ' ')) {
        for (int i = n_rows - 1; i >= 0; i--) {
            if (board[i][y] == ' ') {
                board[i][y] = mark;
                n_moves++;
                return true;
            }
        }
    }
    return false;
}

void FourInARowBoard::display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "| ";
        for (int j = 0; j < n_cols; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------------------------\n";
    }
    cout << "  1   2   3   4   5   6   7\n\n";
}

bool FourInARowBoard::is_winner() {
    // Check for a winner vertically, horizontally, or diagonally
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            char currentSymbol = board[i][j];
            if (currentSymbol != ' ') {
                // Check horizontally
                if (j + 3 < n_cols &&
                    currentSymbol == board[i][j + 1] &&
                    currentSymbol == board[i][j + 2] &&
                    currentSymbol == board[i][j + 3]) {
                    return true;
                }
                // Check vertically
                if (i + 3 < n_rows &&
                    currentSymbol == board[i + 1][j] &&
                    currentSymbol == board[i + 2][j] &&
                    currentSymbol == board[i + 3][j]) {
                    return true;
                }
                // Check diagonally (bottom-left to top-right)
                if (i - 3 >= 0 && j + 3 < n_cols &&
                    currentSymbol == board[i - 1][j + 1] &&
                    currentSymbol == board[i - 2][j + 2] &&
                    currentSymbol == board[i - 3][j + 3]) {
                    return true;
                }
                // Check diagonally (bottom-right to top-left)
                if (i - 3 >= 0 && j - 3 >= 0 &&
                    currentSymbol == board[i - 1][j - 1] &&
                    currentSymbol == board[i - 2][j - 2] &&
                    currentSymbol == board[i - 3][j - 3]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool FourInARowBoard::is_draw() {
    return (n_moves == n_rows * n_cols && !is_winner());
}

bool FourInARowBoard::game_is_over() {
    return n_moves >= n_rows * n_cols;
}

void FourInARowPlayer::get_move(int& x, int& y) {
    cout << "\nPlease enter your move (column number 1-7): ";
    cin >> y;
    y--;  // Adjusting to 0-based index
    x = 0; // In Four-In-A-Row, the move is always at the bottom of the column
}

void FourInARowComputerPlayer::get_move(int& x, int& y) {
    RandomPlayer::get_move(x, y);  // Using the random move generation from the base class
    x = 0;  // In Four-In-A-Row, the move is always at the bottom of the column
}
