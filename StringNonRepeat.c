//QUESTION: Find the first non-repeating character in a string.
//CODE:
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

char firstNonRepeating(char *str) {
    int count[MAX_CHAR] = {0};
    int index[MAX_CHAR];

    for (int i = 0; i < MAX_CHAR; i++) {
        index[i] = -1;
    }

    // Traverse the string and fill count and index arrays
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        count[ch]++;
        if (count[ch] == 1) {
            index[ch] = i;
        } else {
            index[ch] = -1;
        }
    }

    // Find the first non-repeating character
    int first_index = -1;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (index[i] != -1) {
            if (first_index == -1 || index[i] < first_index) {
                first_index = index[i];
            }
        }
    }

    return (first_index != -1) ? str[first_index] : '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    char result = firstNonRepeating(str);
    if (result != '\0') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}
