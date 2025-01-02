#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "genericBoardGame.h"

using namespace std;

bool X_O_5x5_Board::is_draw() {
    return (n_moves == 24 && !is_winner());
}

// Set the board
X_O_5x5_Board::X_O_5x5_Board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_5x5_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

bool X_O_5x5_Board::game_is_over () {
    return n_moves >= 24;
}

// Display the board and the pieces on it
void X_O_5x5_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_5x5_Board::is_winner() {
    if(n_moves<24){
        return false;
    }
    else{
        int score_X=0,score_O=0;
        //check on pos.: 0 1 2 in all rows
        for (int i=0;i<5;i++){
            if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X') score_X++;
            else if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O') score_O++;

            //check on pos.:1 2 3
            if(board[i][1]=='X' && board[i][2]=='X' && board[i][3]=='X') score_X++;
            else if(board[i][1]=='O' && board[i][2]=='O' && board[i][3]=='O') score_O++;

            //check on pos.:2 3 4
            if(board[i][2]=='X' && board[i][3]=='X' && board[i][4]=='X') score_X++;
            else if(board[i][2]=='O' && board[i][3]=='O' && board[i][4]=='O') score_O++;
        }

        //check on pos.: 0 1 2 in all cols
        for (int i=0;i<5;i++){
            if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X') score_X++;
            else if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O') score_O++;

            //check on pos.:1 2 3
            if(board[1][i]=='X' && board[2][i]=='X' && board[3][i]=='X') score_X++;
            else if(board[1][i]=='O' && board[2][i]=='O' && board[3][i]=='O') score_O++;

            //check on pos.:2 3 4
            if(board[2][i]=='X' && board[3][i]=='X' && board[4][i]=='X') score_X++;
            else if(board[2][i]=='O' && board[3][i]=='O' && board[4][i]=='O') score_O++;
        }



        for (int i=0;i<3;i++){

            //check on the principal diagonal
            if(board[0][i]=='X' && board[1][i+1]=='X' && board[2][i+2]=='X') score_X++;
            else if(board[0][i]=='O' && board[1][i+1]=='O' && board[2][i+2]=='O') score_O++;

            if(board[1][i]=='X' && board[2][i+1]=='X' && board[3][i+2]=='X') score_X++;
            else if(board[1][i]=='O' && board[2][i+1]=='O' && board[3][i+2]=='O') score_O++;

            if(board[2][i]=='X' && board[3][i+1]=='X' && board[4][i+2]=='X') score_X++;
            else if(board[2][i+2]=='O' && board[3][i+1]=='O' && board[4][i]=='O') score_O++;

            //check on the secondary diagonal
            if(board[0][i+2]=='X' && board[1][i+1]=='X' && board[2][i]=='X') score_X++;
            else if(board[0][i+2]=='O' && board[1][i+1]=='O' && board[2][i]=='O') score_O++;

            if(board[1][i+2]=='X' && board[2][i+1]=='X' && board[3][i]=='X') score_X++;
            else if(board[1][i+2]=='O' && board[2][i+1]=='O' && board[3][i]=='O') score_O++;

            if(board[2][i+2]=='X' && board[3][i+1]=='X' && board[4][i]=='X') score_X++;
            else if(board[2][i+2]=='O' && board[3][i+1]=='O' && board[4][i]=='O') score_O++;

        }
        if(score_O<score_X)
            return 1;
        else if(score_O>score_X)
            return 1;
        else if(score_O==score_X)
            return 0;

    }
}