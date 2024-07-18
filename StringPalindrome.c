//QUESTION: Check if a string is a palindrome.
//CODE:
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Convert characters to lowercase for case insensitive comparison
        char startChar = tolower(str[start]);
        char endChar = tolower(str[end]);

        // Ignore non-alphanumeric characters
        if (!isalnum(startChar)) {
            start++;
        } else if (!isalnum(endChar)) {
            end--;
        } else if (startChar != endChar) {
            return 0; // Not a palindrome
        } else {
            start++;
            end--;
        }
    }

    return 1; // Is a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
