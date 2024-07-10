/* QUESTION: Reverse an array.*/
/*CODE*/

#include <stdio.h>

// Function to reverse an array
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;
    
    while (start < end) {
        // Swap the elements
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move the pointers
        start++;
        end--;
    }
}

int main() {
    int n, i;
    
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Reverse the array
    reverseArray(arr, n);
    
    // Print the reversed array
    printf("Reversed array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
