#include <iostream>
#include "genericBoardGame.h"

using namespace std;

int main() {
    int gameChoice;
    int playerChoice;
    Player* players[2];

    cout << "Welcome to FCAI Games. :)\n";
    cout << "Choose a game:\n";
    cout << "1. X-O (3x3)\n";
    cout << "2. Pyramid X-O\n";
    cout << "3. Four-In-A-Row\n";
    cout << "4. X-O (5x5)\n";
    cout << "Enter your choice: ";
    cin >> gameChoice;

    if (gameChoice == 1) {
        // X-O (3x3) game
        players[0] = new Player(1, 'x');

        cout << "Press 1 if you want to play with the computer: ";
        cin >> playerChoice;

        if (playerChoice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new RandomPlayer('o', 3);

        GameManager xoGame(new X_O_Board(), players);
        xoGame.run();
    } else if (gameChoice == 2) {
        // Pyramid X-O game
        players[0] = new Player (1, 'x');


        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> playerChoice;
        if (playerChoice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new PyramidRandomPlayer('o');  // Use the new player class

        GameManager PyramicTicTacToe(new PyramicTicTacToe_Board(), players);
        PyramicTicTacToe.run();
    } else if (gameChoice == 3) {
        // Four-In-A-Row game
        cout << "Press 1 if you want to play with a random player: ";
        cin >> playerChoice;

        if (playerChoice == 1)
            players[1] = new FourInARowComputerPlayer('O');
        else
            players[1] = new FourInARowPlayer(2, 'O');

        players[0] = new FourInARowPlayer(1, 'X');

        GameManager fourInARowGame(new FourInARowBoard(), players);
        fourInARowGame.run();
    } else if (gameChoice == 4) {
        // X-O (5x5) game
        players[0] = new Player(1, 'x');

        cout << "Press 1 if you want to play with the computer: ";
        cin >> playerChoice;

        if (playerChoice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new RandomPlayer('o', 5);

        GameManager xo5x5Game(new X_O_5x5_Board(), players);
        xo5x5Game.run();
    } else {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    system("pause");
    return 0;
}
