#include <stdio.h>
#include <conio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int wt[], int val[], int n, int W) {
    int dp[20][20];
    int i, w;
    
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    printf("Maximum value in knapsack: %d\n", dp[n][W]);
}

int main() {
    int n, W, i;
    int wt[20], val[20];
    
    clrscr();
    
    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(wt, val, n, W);

    getch();
    return 0;
}
