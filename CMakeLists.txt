cmake_minimum_required(VERSION 3.24)
project(full_integrated_X_O)

set(CMAKE_CXX_STANDARD 17)

add_executable(full_integrated_X_O main.cpp genericBoardGame.h GameManager.cpp Player.cpp RandomPlayer.cpp RandomPlayer.cpp X_O_Board.cpp FourInARow.cpp X_O_5x5_Board.cpp PyramicTicTacToe.cpp)
