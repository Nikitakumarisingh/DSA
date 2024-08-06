//QUESTION: Next greater element.
//CODE: 
#include <stdio.h>
#include <stdlib.h>

void printNextGreaterElement(int arr[], int n) {
    int *next = (int *)malloc(n * sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;

    // Initialize next[] with -1, assuming no greater element exists
    for (int i = 0; i < n; i++) {
        next[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        // While stack is not empty and the top of the stack is less than the current element
        while (top != -1 && arr[stack[top]] < arr[i]) {
            next[stack[top]] = arr[i];
            top--;
        }
        // Push the current element index onto the stack
        stack[++top] = i;
    }

    // Print the next greater elements
    for (int i = 0; i < n; i++) {
        if (next[i] == -1)
            printf("%d -> %d\n", arr[i], -1);
        else
            printf("%d -> %d\n", arr[i], next[i]);
    }

    // Free the dynamically allocated memory
    free(next);
    free(stack);
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNextGreaterElement(arr, n);

    return 0;
}
