//QUESTION: Longest increasing subsequence.
//CODE:
#include <stdio.h>

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n];  // Array to store the length of the LIS ending at each index
    int maxLIS = 1;  // Variable to keep track of the maximum LIS found

    // Initialize the LIS values for all indices as 1
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Compute the LIS values for each element of the array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Find the maximum value in the LIS array
    for (int i = 0; i < n; i++) {
        if (maxLIS < lis[i]) {
            maxLIS = lis[i];
        }
    }

    return maxLIS;  // Return the length of the longest increasing subsequence
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    int result = longestIncreasingSubsequence(arr, n);  // Find the LIS
    printf("Length of Longest Increasing Subsequence is: %d\n", result);  // Print the result

    return 0;
}
