//QUESTION: Print all subsets of a set.
//CODE:
#include <stdio.h>

#define MAX 100  // Define a maximum size for the set

void printSubset(int subset[], int subsetSize) {
    // Print the current subset
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void findSubsets(int set[], int n, int index, int subset[], int subsetSize) {
    // If the current index is equal to the set size, print the current subset
    if (index == n) {
        printSubset(subset, subsetSize);
        return;
    }

    // Exclude the current element and move to the next
    findSubsets(set, n, index + 1, subset, subsetSize);

    // Include the current element in the subset and move to the next
    subset[subsetSize] = set[index];
    findSubsets(set, n, index + 1, subset, subsetSize + 1);
}

int main() {
    int set[MAX];  // Array to hold the set elements
    int n;         // Number of elements in the set

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int subset[MAX];  // Array to hold the current subset
    printf("All subsets of the given set are:\n");
    findSubsets(set, n, 0, subset, 0);

    return 0;
}

