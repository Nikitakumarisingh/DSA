//QUESTION: Edit distance problem.
//CODE: 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three integers
int min(int x, int y, int z) {
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

// Function to compute the edit distance between two strings
int editDistance(char *str1, char *str2, int m, int n) {
    // Create a 2D array to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill dp[][] in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If the first string is empty, insert all characters of the second string
            if (i == 0)
                dp[i][j] = j;  // Minimum operations = j

            // If the second string is empty, remove all characters of the first string
            else if (j == 0)
                dp[i][j] = i;  // Minimum operations = i

            // If the last characters are the same, ignore the last character
            // and recur for the remaining substring
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If the last character is different, consider all possibilities
            // and find the minimum among them
            else
                dp[i][j] = 1 + min(dp[i][j - 1],    // Insert
                                   dp[i - 1][j],    // Remove
                                   dp[i - 1][j - 1] // Replace
                                  );
        }
    }

    return dp[m][n];
}

int main() {
    char str1[100], str2[100];

    // Input strings
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    // Calculate and print the edit distance
    printf("Edit Distance: %d\n", editDistance(str1, str2, m, n));

    return 0;
}
