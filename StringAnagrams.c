//OUESTION: Check if two strings are anagrams of each other.
//CODE:
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CHAR_SET_SIZE 256 // Assuming ASCII character set

bool areAnagrams(char* str1, char* str2) {
    // If the lengths of the strings are different, they cannot be anagrams
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    // Initialize count arrays for all characters to 0
    int count1[CHAR_SET_SIZE] = {0};
    int count2[CHAR_SET_SIZE] = {0};

    // Count the frequency of each character in both strings
    for (int i = 0; str1[i] && str2[i]; i++) {
        count1[(unsigned char)str1[i]]++;
        count2[(unsigned char)str2[i]]++;
    }

    // Compare the frequency counts of each character
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    scanf("%99s", str1);

    printf("Enter the second string: ");
    scanf("%99s", str2);

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams of each other.\n");
    } else {
        printf("The strings are not anagrams of each other.\n");
    }

    return 0;
}
