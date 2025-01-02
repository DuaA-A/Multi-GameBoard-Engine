<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <h1>Multi-GameBoard-Engine</h1>
    <p>
        A robust, object-oriented game engine that supports multiple board games, including 
        advanced versions of Tic Tac Toe and Four in a Row, with flexible player configurations. 
        This project leverages C++ to deliver a scalable framework for creating and managing board games 
        for two or more players.
    </p>
    <h2>Features</h2>
    <ul>
        <li><strong>Multi-Game Support</strong>: Includes standard Tic Tac Toe, 5x5 Tic Tac Toe, 
            Pyramid Tic Tac Toe, and Four in a Row.</li>
        <li><strong>Customizable Players</strong>: Allows different types of players, including 
            human players and AI bots (e.g., RandomPlayer).</li>
        <li><strong>Flexible Game Rules</strong>: Configurable game board sizes and winning conditions.</li>
        <li><strong>Object-Oriented Design</strong>: Modular classes for managing game boards, players, 
            and game logic independently.</li>
        <li><strong>Scalable Player Count</strong>: Supports games with more than two players, adding variety and complexity.</li>
    </ul>
    <h2>Project Structure</h2>
    <pre>
Multi-GameBoard-Engine/
├── src/
│   ├── main.cpp               # Entry point of the program
│   ├── X_O_Board.cpp          # Logic for standard Tic Tac Toe
│   ├── X_O_5x5_Board.cpp      # Logic for 5x5 Tic Tac Toe
│   ├── PyramidTicTacToe.cpp   # Logic for Pyramid Tic Tac Toe
│   ├── FourInARow.cpp         # Logic for Four in a Row
│   ├── RandomPlayer.cpp       # AI player logic
│   ├── Player.cpp             # Player interface implementation
│   ├── GameManager.cpp        # Game management logic
├── include/
│   ├── BoardGame_Classes.hpp  # Base classes and interfaces
│   ├── genericBoardGame.hpp   # Generic board game utilities
│   ├── GameManager.hpp        # Game management interface
├── build/
│   └── ...                    # Compiled binaries
└── README.html                # Project documentation
    </pre>
    <h2>Supported Games</h2>
    <ul>
        <li><strong>Standard Tic Tac Toe</strong>: The classic 3x3 board with two players.</li>
        <li><strong>5x5 Tic Tac Toe</strong>: A larger version with increased complexity.</li>
        <li><strong>Pyramid Tic Tac Toe</strong>: A unique twist with a triangular board.</li>
        <li><strong>Four in a Row</strong>: Connect four pieces in a row to win.</li>
    </ul>
    <h2>Code Explanation</h2>
    <p>
        The engine uses a modular architecture where each game board type, player type, 
        and game manager is implemented in separate classes to ensure extensibility. 
        For example:
    </p>
    <ul>
        <li><strong>GameManager</strong>: Manages the game loop, player turns, and win/draw detection.</li>
        <li><strong>Board</strong>: Encapsulates game board states and updates.</li>
        <li><strong>Player</strong>: Abstracts player behavior, allowing custom implementations like AI.</li>
    </ul>
    <h3>Example Snippet</h3>
    <pre>
void GameManager::run() {
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i = 0; i < player_count; ++i) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
    </pre>
    <h2>Getting Started</h2>
    <h3>Prerequisites</h3>
    <ul>
        <li>A C++ compiler supporting C++11 or higher.</li>
        <li>A text editor or IDE for C++ development.</li>
    </ul>
    <h3>Building and Running</h3>
    <ol>
        <li>Clone the repository:
            <pre>git clone https://github.com/your-username/Multi-GameBoard-Engine.git</pre>
        </li>
        <li>Navigate to the directory:
            <pre>cd Multi-GameBoard-Engine</pre>
        </li>
        <li>Compile the code:
            <pre>g++ -std=c++11 src/main.cpp -o build/MultiGameEngine</pre>
        </li>
        <li>Run the game:
            <pre>./build/MultiGameEngine</pre>
        </li>
    </ol>
    <h2>Future Enhancements</h2>
    <ul>
        <li>Add more AI strategies for competitive gameplay.</li>
        <li>Include visual enhancements with a GUI.</li>
        <li>Support custom rules for more game variations.</li>
    </ul>
    <h2>Contributing</h2>
    <p>
        Contributions are welcome! Feel free to fork the repository and submit pull requests 
        for new features or bug fixes.
    </p>
    <h2>License</h2>
    <p>
        This project is licensed under the MIT License. See the LICENSE file for details.
    </p>
    <h2>Author</h2>
    <p>
        <strong>[Your Name]</strong><br>
        Feel free to reach out with questions or suggestions!
    </p>
</body>
</html>
