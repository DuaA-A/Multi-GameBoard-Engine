#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "genericBoardGame.h"

using namespace std;

PyramicTicTacToe_Board::PyramicTicTacToe_Board() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++){
            board[i][j] = 0;
        }
    }
}
void PyramicTicTacToe_Board::display_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if( i == 0 && j == 2) {
                cout <<"                     \n                        -----------";
                cout << "                    \n                        | ";
                cout << " (" << i << "," << j << ")";
                cout << setw(0) << board[i][j] << " |";
            } else if(i == 0) {
                board[i][j] = ' ';
            } else if(i == 1 && (j == 1 || j == 2 || j== 3)) {
                cout <<       "      |" ;
                cout << " ( " << i << "," << j << " ) ";
                cout << setw(-10) << board[i][j] << " |";
            } else if(i == 2) {
                cout <<   " | ";
                cout << " (" << i << "," << j << ")";
                cout << setw(-5) << board[i][j] << " |";
            }


        }
        if(i==1){
            cout << "\n -------------------------------------------------------\n";
        }
        else if(i==2){
            cout << "\n-----------------------------------------------------------\n";
        }
        else{
            cout << "\n              ------------------------------\n";
        }
    }
    cout << endl;
}
bool PyramicTicTacToe_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if(x==0 && y!=2){
        return false;
    }
    else if(x==1 && (y==0||y==4)){
        return false;
    }
    else if (board[x][y] == 0) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
bool PyramicTicTacToe_Board::is_winner() {
    // Diagonal checks
    if ((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!=0) ||
        (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board [2][4]!= 0)) {
        return true;
    }

    // Horizontal checks
    if ((board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2]!=0)) {
        return true;
    }

    // Vertical checks
    if ((board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2]!=0) ||
        (board[2][2] == board[2][3] && board[2][3] == board[2][4] && board[2][4]!=0) ||
        (board[1][1] == board[1][2] && board[1][2] == board[1][3] && board[1][3]!=0) ||
        (board[2][1]==board[2][2]&& board[2][2]==board[2][3] && board[2][3]!=0)) {
        return true;
    }

    return false;  // If no winning condition met
}

bool PyramicTicTacToe_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}
bool PyramicTicTacToe_Board::game_is_over () {
    return n_moves >= 9;
}


PyramidRandomPlayer::PyramidRandomPlayer(char symbol) : Player(symbol) {
    // Additional initialization for PyramidRandomPlayer if needed
}

void PyramidRandomPlayer::get_move(int& x, int& y) {
    // Generate random move for Pyramid X-O
    x = rand() % 3;  // Random row (0, 1, or 2)
    y = rand() % 5;  // Random column (0, 1, 2, 3, or 4)
}

