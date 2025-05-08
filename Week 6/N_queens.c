#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the chessboard
void print_board(int** board, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1)
                printf("Q ");  // Queen is placed
            else
                printf(". ");  // Empty space
        }
        printf("\n");
    }
}

// Check if it's safe to place a queen at board[row][col]
bool is_safe(int** board, int row, int col, int n) {
    // Check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

// Solve the N-Queens problem using backtracking
bool solve_n_queens(int** board, int row, int n) {
    // If all queens are placed, return true
    if(row >= n)
        return true;

    // Try all columns in the current row
    for(int col = 0; col < n; col++) {
        // Check if it's safe to place the queen
        if(is_safe(board, row, col, n)) {
            // Place queen
            board[row][col] = 1;

            // Recur to place the queen in the next row
            if(solve_n_queens(board, row + 1, n))
                return true;

            // If placing queen in this position doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

// Function to solve the N-Queens problem
void n_queens(int n) {
    // Create an empty board
    int** board = (int**)calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++) {
        board[i] = (int*)calloc(n, sizeof(int));
    }

    // Try to solve the problem starting from the first row
    if(solve_n_queens(board, 0, n)) {
        print_board(board, n);
    } else {
        printf("Solution does not exist.\n");
    }

    // Free the memory for the board
    for(int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    // Solve the N-Queens problem
    n_queens(n);

    return 0;
}
