//Question: Move all the negative elements to one side of the array.
//CODE:
#include <stdio.h>

// Function to move all negative elements to one side
void moveNegativesToLeft(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        // If the left element is negative, move the left pointer to the right
        if (arr[left] < 0) {
            left++;
        }
        // If the right element is positive, move the right pointer to the left
        else if (arr[right] >= 0) {
            right--;
        }
        // If left is positive and right is negative, swap them
        else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = { -1, 2, -3, 4, -5, 6, -7, 8, -9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    moveNegativesToLeft(arr, size);

    printf("\nArray after moving negatives to one side:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


