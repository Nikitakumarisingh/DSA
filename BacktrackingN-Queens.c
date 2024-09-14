//QUESTION: Solve the N-Queens problem for a 4x4 board.
//CODE: 
#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the solution (chessboard)
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check the same column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve N-Queens using backtracking
bool solveNQueensUtil(int board[N][N], int row) {
    // If all queens are placed
    if (row >= N)
        return true;

    // Consider this row and try placing a queen in all columns one by one
    for (int col = 0; col < N; col++) {
        // Check if placing a queen here is safe
        if (isSafe(board, row, col)) {
            // Place a queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, row + 1))
                return true;

            // If placing a queen here doesn't lead to a solution, backtrack
            board[row][col] = 0;  // Remove the queen
        }
    }

    // If no column is suitable, return false
    return false;
}

// Function to initialize the board and start solving
bool solveNQueens() {
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0) == false) {
        printf("Solution does not exist\n");
        return false;
    }

    // Print the solution
    printSolution(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}
