//QUESTION: Fibonacci sequence.
//CODE: 
#include <stdio.h>

// Function to calculate nth Fibonacci number using Dynamic Programming
int fibonacci(int n) {
    // Array to store the Fibonacci numbers
    int fib[n + 1];
    
    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    // Fill the array with Fibonacci values up to nth number
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Return the nth Fibonacci number
    return fib[n];
}

int main() {
    int n;

    // Ask user to input the position of Fibonacci number they want
    printf("Enter the position of the Fibonacci number: ");
    scanf("%d", &n);

    // Check for valid input
    if (n < 0) {
        printf("Position can't be negative.\n");
        return 1;
    }

    // Call the fibonacci function and print the result
    int result = fibonacci(n);
    printf("Fibonacci number at position %d is: %d\n", n, result);

    return 0;
}
