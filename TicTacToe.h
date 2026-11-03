#ifndef TICTACTOE_H
#define TICTACTOE_H
 //A Tic-Tac-Toe game class that manages the board, player turns, and gameplay
class TicTacToe {
    private:
            char theBoard[3][3]; //The 3x3 game grid ('X', 'O', or an empty space)
            char currentPlayer;  // Keeps track of whose turn it is (X OR O)

    public:
    // Sets up a brand new game board and makes player 'X' go first
        TicTacToe();

// Prints the current game board to the screen
        void displayBoard();


// Places the player's mark at a specific row and column (0, 1, or 2)
    // Returns true if the move was good move or false if it was wrong
        bool makeMove(int row, int col);


// Switches the turn to the other player ('X' becomes 'O', and 'O' becomes 'X')
        void switchPlayer();

// Checks if the current player has won the game
        bool checkWin();

// Checks if the board is completely full and the game ends in a tie
        bool checkTie();

// Starts the game and handles the main loop taking turns and getting input
        void play();

};

#endif // TICTACTOE_H Finshes