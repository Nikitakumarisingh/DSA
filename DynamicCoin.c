//QUESTION: Coin change problem.
//CODE:
#include <stdio.h>

// Function to find the number of ways to get the desired amount
int coinChange(int coins[], int n, int amount) {
    // Create a table to store results of subproblems
    int dp[amount + 1];
    
    // Initialize all values to 0
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    
    // Base case: there is one way to make the amount 0
    dp[0] = 1;
    
    // Iterate over all coin denominations
    for (int i = 0; i < n; i++) {
        // Update dp[] values for all amounts greater than or equal to the current coin's value
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    // The answer is in dp[amount]
    return dp[amount];
}

int main() {
    // Example coin denominations
    int coins[] = {1, 2, 5};  // Available coin denominations
    int n = sizeof(coins) / sizeof(coins[0]);  // Number of coin types
    int amount = 11;  // Total amount

    // Call the function and display the result
    int result = coinChange(coins, n, amount);
    printf("Number of ways to make change for %d is: %d\n", amount, result);

    return 0;
}
