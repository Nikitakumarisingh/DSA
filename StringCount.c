//QUESTION: Count and say problem.
//CODE:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate the next term in the sequence
char* countAndSay(char* input) {
    int len = strlen(input);
    char* result = (char*)malloc(len * 2 + 1); // Allocate enough space for the result
    int index = 0;

    for (int i = 0; i < len; i++) {
        int count = 1; // Initialize count of the current digit

        // Count occurrences of the same digit
        while (i + 1 < len && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Append count and the digit to the result string
        index += sprintf(result + index, "%d%c", count, input[i]);
    }

    result[index] = '\0'; // Null-terminate the result string
    return result;
}

// Function to generate the n-th term of the count-and-say sequence
char* countAndSaySequence(int n) {
    if (n <= 0) return "";

    char* result = (char*)malloc(2);
    strcpy(result, "1");

    for (int i = 1; i < n; i++) {
        char* nextTerm = countAndSay(result);
        free(result); // Free the previous term
        result = nextTerm;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    char* result = countAndSaySequence(n);
    printf("The %d-th term in the count-and-say sequence is: %s\n", n, result);

    free(result); // Free the final result string
    return 0;
}
