//QUESTION: Find the longest contiguous subarray with an equal number of 0s and 1s.
//CODE: 
#include <stdio.h>
#include <stdlib.h>

int findMaxLength(int* nums, int numsSize) {
    int maxLength = 0;
    int sum = 0;
    int* hashMap = (int*)malloc((2 * numsSize + 1) * sizeof(int));

    // Initialize hashMap with -1
    for (int i = 0; i < 2 * numsSize + 1; i++) {
        hashMap[i] = -1;
    }

    // Traverse the array
    for (int i = 0; i < numsSize; i++) {
        // Convert 0s to -1s
        sum += (nums[i] == 0) ? -1 : 1;

        // When subarray starts from the beginning of the array
        if (sum == 0) {
            maxLength = i + 1;
        }

        // If sum is seen before, update maxLength
        if (hashMap[sum + numsSize] != -1) {
            if (maxLength < (i - hashMap[sum + numsSize])) {
                maxLength = i - hashMap[sum + numsSize];
            }
        } else {
            // Store first occurrence of the sum
            hashMap[sum + numsSize] = i;
        }
    }

    free(hashMap);
    return maxLength;
}

int main() {
    int nums[] = {0, 1, 0, 1, 0, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int maxLength = findMaxLength(nums, numsSize);
    printf("The length of the longest contiguous subarray with equal number of 0s and 1s is %d\n", maxLength);
    return 0;
}



//CONCEPT USED:
//Concept of prefix sums and a hash map to keep track of the first occurrence of a particular prefix sum. 
//This approach ensures an efficient solution with a time complexity of O(n).
