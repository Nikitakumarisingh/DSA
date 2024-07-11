//Find the "Kth" max and min element of an array.
//Code
#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort (modified to handle kth max and min)
int partition(int arr[], int low, int high, int k) {
    int pivot = arr[high];
    int i = (low - 1);  // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot (for kth max)
        // or greater than or equal to pivot (for kth min)
        if (arr[j] <= pivot && (k > 0 || arr[j] >= pivot)) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive function to find the kth maximum and minimum elements
void findKthMaxMin(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivot_index = partition(arr, low, high, k);

        // If k is smaller than number of elements on right side
        if (k - 1 > 0 && k - 1 < high - pivot_index) {
            findKthMaxMin(arr, pivot_index + 1, high, k - 1);
        }

        // If k is greater than number of elements on left side for kth max
        // (or less than for kth min)
        if (k < high - pivot_index + 1) {
            findKthMaxMin(arr, low, pivot_index - 1, k);
        }
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;  // Find the 3rd maximum and minimum elements

    findKthMaxMin(arr, 0, n - 1, k);

    printf("Kth maximum element: %d\n", arr[n - k]);
    printf("Kth minimum element: %d\n", arr[k - 1]);

    return 0;
}
