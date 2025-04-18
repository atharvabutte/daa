#include <stdio.h>
#include <conio.h>

#define N 4

int board[4];
int found = 0;

int isSafe(int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        if (board[i] == col || (board[i] - col == i - row) || (board[i] - col == row - i))
            return 0;
    }
    return 1;
}

void printSolution() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    int col;
    if (found) return;

    if (row == N) {
        printSolution();
        found = 1;
        return;
    }

    for (col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

void main() {
    clrscr();
    solve(0);
    getch();
}
