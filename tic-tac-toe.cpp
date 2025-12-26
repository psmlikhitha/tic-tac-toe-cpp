#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    const char PLAYER = 'X';
    const char COMPUTER = 'O';

public:
    TicTacToe() {
        resetBoard();
    }

    void resetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() {
        cout << "\n";
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        cout << "---|---|---\n";
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        cout << "---|---|---\n";
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
        cout << "\n";
    }

    int checkFreeSpaces() {
        int freeSpaces = 9;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != ' ') {
                    freeSpaces--;
                }
            }
        }
        return freeSpaces;
    }

    void playerMove() {
        int row, col;

        do {
            cout << "Enter row (1-3): ";
            cin >> row;
            cout << "Enter column (1-3): ";
            cin >> col;

            row--;
            col--;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move! Try again.\n";
            } else {
                board[row][col] = PLAYER;
                break;
            }
        } while (true);
    }

    void computerMove() {
        int row, col;
        if (checkFreeSpaces() > 0) {
            do {
                row = rand() % 3;
                col = rand() % 3;
            } while (board[row][col] != ' ');
            board[row][col] = COMPUTER;
        }
    }

    char checkWinner() {
        // Rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] &&
                board[i][0] == board[i][2] &&
                board[i][0] != ' ') {
                return board[i][0];
            }
        }

        // Columns
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] &&
                board[0][i] == board[2][i] &&
                board[0][i] != ' ') {
                return board[0][i];
            }
        }

        // Diagonals
        if (board[0][0] == board[1][1] &&
            board[0][0] == board[2][2] &&
            board[0][0] != ' ') {
            return board[0][0];
        }

        if (board[0][2] == board[1][1] &&
            board[0][2] == board[2][0] &&
            board[0][2] != ' ') {
            return board[0][2];
        }

        return ' ';
    }

    void printWinner(char winner) {
        cout << "\n--- Game Over ---\n";
        if (winner == PLAYER) {
            cout << "Congratulations! You won!\n";
        } else if (winner == COMPUTER) {
            cout << "You lost! Better luck next time.\n";
        } else {
            cout << "It's a tie!\n";
        }
        cout << "Thanks for playing Tic Tac Toe!\n";
    }

    void playGame() {
        char winner = ' ';
        while (winner == ' ' && checkFreeSpaces() != 0) {
            printBoard();
            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0) break;

            computerMove();
            winner = checkWinner();
        }
        printBoard();
        printWinner(winner);
    }
};

int main() {
    srand(time(0));
    while(true)
    {
        cout << "=====================================\n";
        cout << "       Welcome to Tic Tac Toe         \n";
        cout << "=====================================\n";
        cout << "Player: X | Computer: O\n";

        TicTacToe game;
        game.playGame();
        int choice;
        cout<<"Do you want to play again??? 0/1 ";
        cin>>choice;
        if(!choice)
            break;
    }
    
    return 0;
}
