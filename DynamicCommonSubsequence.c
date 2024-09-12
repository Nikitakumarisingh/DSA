//QUESTION: Longest common subsequence.
//CODE:
#include <stdio.h>
#include <string.h>

// Function to find the length of the Longest Common Subsequence
int lcs(char *X, char *Y, int m, int n) {
    // Create a table to store lengths of longest common subsequence
    // of substring X[0..m-1] and Y[0..n-1]
    int L[m + 1][n + 1];

    // Building the table in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0; // Initialize first row and first column with 0
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; // If characters match, increment diagonal value by 1
            } else {
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1]; // Take the maximum value from left or top
            }
        }
    }

    // The length of LCS will be in L[m][n]
    return L[m][n];
}

int main() {
    char X[100], Y[100];
    
    // Input strings
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // Find and print the length of LCS
    printf("Length of Longest Common Subsequence is %d\n", lcs(X, Y, m, n));

    return 0;
}
