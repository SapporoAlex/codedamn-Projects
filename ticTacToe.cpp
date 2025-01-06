#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

bool run = true;
bool gameOver = false;
bool playerTurn = false;
bool comTurn = false;
int turn;

int playerChoice;
int comChoice;

// Function to generate a random number between 1 and 9
int generateRandomNumber() {
    return std::rand() % 9 + 1;
}

// Function to decide the first player randomly
int decideFirstPlayer() {
    return std::rand() % 2 + 1;
}

// Function to check for a win or draw
void checkWin(const std::vector<std::vector<char>>& grid) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '-') {
            if (grid[i][0] == 'X') {
                std::cout << "Computer wins!\n";
            } else {
                std::cout << "Player wins!\n";
            }
            gameOver = true;
            return;
        }

        // Check columns
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '-') {
            if (grid[0][i] == 'X') {
                std::cout << "Computer wins!\n";
            } else {
                std::cout << "Player wins!\n";
            }
            gameOver = true;
            return;
        }
    }

    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '-') {
        if (grid[0][0] == 'X') {
            std::cout << "Computer wins!\n";
        } else {
            std::cout << "Player wins!\n";
        }
        gameOver = true;
        return;
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '-') {
        if (grid[0][2] == 'X') {
            std::cout << "Computer wins!\n";
        } else {
            std::cout << "Player wins!\n";
        }
        gameOver = true;
        return;
    }

    // Check for a draw
    bool isDraw = true;
    for (const auto& row : grid) {
        for (char cell : row) {
            if (cell == '-') {
                isDraw = false;
                break;
            }
        }
    }

    if (isDraw) {
        std::cout << "It's a draw!\n";
        gameOver = true;
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<std::vector<char>> grid(3, std::vector<char>(3, '-'));
    turn = decideFirstPlayer();

    std::cout << (turn == 1 ? "Player goes first!\n" : "Computer goes first!\n");

    while (run) {
        // Display the grid
        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell << " ";
            }
            std::cout << "\n";
        }

        if (gameOver) {
            break;
        }

        if (turn == 1) { // Player's turn
            playerTurn = true;
            while (playerTurn) {
                std::cout << "Player's turn. Choose a position (1-9): ";
                std::cin >> playerChoice;

                if (playerChoice < 1 || playerChoice > 9) {
                    std::cout << "Invalid choice. Try again.\n";
                    continue;
                }

                int row = (playerChoice - 1) / 3;
                int col = (playerChoice - 1) % 3;

                if (grid[row][col] == '-') {
                    grid[row][col] = 'O';
                    playerTurn = false;
                    turn = 2; // Switch to computer's turn
                } else {
                    std::cout << "Position already taken. Try again.\n";
                }
            }
        } else { // Computer's turn
            comTurn = true;
            while (comTurn) {
                comChoice = generateRandomNumber();

                int row = (comChoice - 1) / 3;
                int col = (comChoice - 1) % 3;

                if (grid[row][col] == '-') {
                    std::cout << "Computer chooses position " << comChoice << ".\n";
                    grid[row][col] = 'X';
                    comTurn = false;
                    turn = 1; // Switch to player's turn
                }
            }
        }

        checkWin(grid);
    }

    return 0;
}
