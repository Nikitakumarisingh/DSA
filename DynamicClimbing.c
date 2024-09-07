//QUESTION: Climbing stairs problem.
//CONCEPT: The "Climbing Stairs" problem is a classic dynamic programming problem where you need to find the number of distinct ways to climb to the top of a staircase with n steps, given that you can either take 1 or 2 steps at a time.
//CODE:
#include <stdio.h>

// Function to calculate the number of ways to climb n stairs
int climbStairs(int n) {
    // Base cases
    if (n <= 1) {
        return 1;
    }

    // Array to store the number of ways to reach each step
    int dp[n + 1];

    // Initial values
    dp[0] = 1;  // 1 way to stay at the ground (0th step)
    dp[1] = 1;  // 1 way to reach the 1st step (single step)

    // Fill the dp array
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Number of ways to reach current step
    }

    // The number of ways to reach the nth step
    return dp[n];
}

int main() {
    int n;

    // Input the number of stairs
    printf("Enter the number of stairs: ");
    scanf("%d", &n);

    // Calculate and print the number of ways to climb n stairs
    int result = climbStairs(n);
    printf("Number of ways to climb %d stairs: %d\n", n, result);

    return 0;
}
