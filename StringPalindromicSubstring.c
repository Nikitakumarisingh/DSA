//QUESTION: Longest palindromic substring.
//CODE:
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Function to expand around the center and find the longest palindrome
void expandAroundCenter(char* s, int left, int right, int* start, int* maxLength) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        if (right - left + 1 > *maxLength) {
            *start = left;
            *maxLength = right - left + 1;
        }
        left--;
        right++;
    }
}

// Function to find the longest palindromic substring
void longestPalindromicSubstring(char* s) {
    int start = 0;
    int maxLength = 1;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        // Odd length palindromes (single character center)
        expandAroundCenter(s, i, i, &start, &maxLength);
        // Even length palindromes (two character center)
        expandAroundCenter(s, i, i + 1, &start, &maxLength);
    }

    printf("Longest palindromic substring: ");
    for (int i = start; i < start + maxLength; i++) {
        putchar(s[i]);
    }
    printf("\n");
}

int main() {
    char s[MAX_LEN];

    printf("Enter a string: ");
    fgets(s, MAX_LEN, stdin);
    
    // Remove the newline character if it exists
    s[strcspn(s, "\n")] = '\0';

    longestPalindromicSubstring(s);

    return 0;
}
