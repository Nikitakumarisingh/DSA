//QUESTION: Longest common prefix.
//CODE:
#include <stdio.h>
#include <string.h>

// Function to find the minimum length among an array of strings
int findMinLength(char arr[][100], int n) {
    int minLen = strlen(arr[0]);
    for (int i = 1; i < n; i++) {
        if (strlen(arr[i]) < minLen) {
            minLen = strlen(arr[i]);
        }
    }
    return minLen;
}

// Function to find the longest common prefix
void longestCommonPrefix(char arr[][100], int n) {
    int minLength = findMinLength(arr, n);

    char result[minLength + 1];
    result[minLength] = '\0';

    for (int i = 0; i < minLength; i++) {
        char currentChar = arr[0][i];
        for (int j = 1; j < n; j++) {
            if (arr[j][i] != currentChar) {
                result[i] = '\0';
                printf("Longest Common Prefix: %s\n", result);
                return;
            }
        }
        result[i] = currentChar;
    }

    printf("Longest Common Prefix: %s\n", result);
}

int main() {
    char arr[][100] = {"flower", "flow", "flight"};
    int n = sizeof(arr) / sizeof(arr[0]);
    longestCommonPrefix(arr, n);
    return 0;
}
