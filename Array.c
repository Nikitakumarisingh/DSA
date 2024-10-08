/*TOPIC: Array
QUESTION: Finding the Largest Element in an Array
Logic and Explanation:
APPROCH: Linear search. 
The idea is to traverse the array from the beginning to the end while keeping track of the maximum value encountered so far.
1. Initialize: Start by assuming the first element of the array is the largest. Initialize a variable `max_element` to hold this value.
2. Traverse the Array: Iterate through each element in the array, starting from the second element (index 1).
3. Update the Maximum: For each element, compare it with the current `max_element`. If the current element is greater than `max_element`, update `max_element` to this element.
4. Completion: After traversing all the elements, `max_element` will hold the largest value in the array.
CODE*/
#include <stdio.h>
#include <limits.h>

// Function to find the largest element in an array
int findLargestElement(int arr[], int n) {
    // Check if the array is empty
    if (n == 0) {
        printf("Array is empty\n");
        return INT_MIN;  // Returning INT_MIN to indicate error
    }

    // Initialize max_element with the first element of the array
    int max_element = arr[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Update max_element if the current element is greater
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Return the max_element
    return max_element;
}

int main() {
    int array[] = {3, 5, 7, 2, 8, 1};
    int n = sizeof(array) / sizeof(array[0]);

    int largest_element = findLargestElement(array, n);
    
    if (largest_element != INT_MIN) {
        printf("The largest element in the array is: %d\n", largest_element);
    }

    return 0;
}

/*Explanation of the C Code:
Function Definition:
The function findLargestElement takes an array arr and its size n as input parameters.
If the array is empty (n == 0), it prints an error message and returns INT_MIN to indicate an error.
Initialize max_element:

The variable max_element is initialized with the first element of the array (arr[0]).
Traverse the Array:

A for loop starts from the second element (index 1) and goes till the end of the array (i < n).
Inside the loop, each element is compared with max_element. If the current element is greater, max_element is updated.
Return Result:

After the loop ends, the function returns the max_element.
Main Function:

The main function defines an array and calculates its size.
It calls the findLargestElement function with the array and its size.
If the largest element is not INT_MIN, it prints the largest element.
This code will find and print the largest element in the given array [3, 5, 7, 2, 8, 1], which is 8.*/




