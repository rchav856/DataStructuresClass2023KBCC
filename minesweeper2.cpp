// Randy Chauarria, Minesweeper game
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 8;  // Size of the Minesweeper board
const int BOMBS = 10; // Number of bombs

vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> revealed(SIZE, vector<bool>(SIZE, false));

void placeBombs() {
    srand(time(0));
    int bombsPlaced = 0;
    while (bombsPlaced < BOMBS) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] != -1) {
            board[x][y] = -1; // -1 represents a bomb
            bombsPlaced++;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int numx = x + i;
                    int numy = y + j;
                    if (numx >= 0 && numx < SIZE && numy >= 0 && numy < SIZE && board[numx][numy] != -1) {
                        board[numx][numy]++;
                    }
                }
            }
        }
    }
}

// Prints current board to user when called
void printBoard() {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                if (board[i][j] == -1) {
                    cout << "X ";
                } 
				else {
                    cout << board[i][j] << " ";
                }
            } 
			else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

// Reveals number of bombs around cell, and also ends game if bomb is hit
void revealCell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        cout << "Invalid cell!\n";
        return;
    }
    if (revealed[x][y]) {
        cout << "Cell already revealed.\n";
    } 
	else {
        revealed[x][y] = true;
        if (board[x][y] == -1) {
            cout << "Game over! You hit a bomb.\n";
            printBoard();
            exit(0);
        } 
		else {
            cout << "Number of bombs around cell (" << x << ", " << y << "): " << board[x][y] << "\n";
            printBoard();
        }
    }
}

int main() {
    placeBombs();
    printBoard();
    int x, y;
    while (true) {
        cout << "Enter the coordinates to reveal (x y): ";
        cin >> x >> y;
        revealCell(x, y);
	}
    return 0;
}

