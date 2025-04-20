#include <stdio.h>
#include <conio.h>

#define MAX 10

int board[MAX][MAX];

void printBoard(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] != 0) {
                printf("Q%d ", board[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int isSafe(int row, int col, int n) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (board[i][col] != 0) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] != 0) {
            return 0;
        }
    }

    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] != 0) {
            return 0;
        }
    }

    return 1;
}

int solveNQueens(int row, int n, int queenCount) {
    int col;
    if (row == n) {
        return 1;
    }

    for (col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = queenCount;

            if (solveNQueens(row + 1, n, queenCount + 1)) {
                return 1;
            }

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int n, i, j;
    clrscr();
    printf("Enter the value of N (size of board): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0, n, 1)) {
        printf("Solution to the N-Queen problem:\n");
        printBoard(n);
    } else {
        printf("No solution found for N = %d\n", n);
    }

    getch();
    return 0;
}
