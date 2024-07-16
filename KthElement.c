//QUESTION: Find the "Kth" smallest/largest element in a sorted matrix.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a min heap node
typedef struct {
    int value;
    int row;
    int col;
} MinHeapNode;

// A structure to represent a min heap
typedef struct {
    MinHeapNode* heapArray;
    int size;
} MinHeap;

// Function to swap two min heap nodes
void swap(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to create a new min heap node
MinHeapNode newMinHeapNode(int value, int row, int col) {
    MinHeapNode node;
    node.value = value;
    node.row = row;
    node.col = col;
    return node;
}

// A utility function to create a min heap of given capacity
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->heapArray = (MinHeapNode*)malloc(capacity * sizeof(MinHeapNode));
    minHeap->size = 0;
    return minHeap;
}

// A utility function to heapify the node at idx
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->heapArray[left].value < minHeap->heapArray[smallest].value) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->heapArray[right].value < minHeap->heapArray[smallest].value) {
        smallest = right;
    }
    if (smallest != idx) {
        swap(&minHeap->heapArray[smallest], &minHeap->heapArray[idx]);
        minHeapify(minHeap, smallest);
    }
}

// A utility function to extract the minimum element from the heap
MinHeapNode extractMin(MinHeap* minHeap) {
    MinHeapNode root = minHeap->heapArray[0];
    minHeap->heapArray[0] = minHeap->heapArray[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return root;
}

// A utility function to insert a new node to the heap
void insertMinHeap(MinHeap* minHeap, MinHeapNode node) {
    int i = minHeap->size++;
    minHeap->heapArray[i] = node;

    while (i && minHeap->heapArray[i].value < minHeap->heapArray[(i - 1) / 2].value) {
        swap(&minHeap->heapArray[i], &minHeap->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to find the Kth smallest element in a sorted matrix
int kthSmallest(int matrix[4][4], int n, int k) {
    MinHeap* minHeap = createMinHeap(n);

    for (int i = 0; i < n; i++) {
        minHeap->heapArray[i] = newMinHeapNode(matrix[i][0], i, 0);
    }
    minHeap->size = n;

    MinHeapNode node;
    for (int i = 0; i < k; i++) {
        node = extractMin(minHeap);
        int nextVal = (node.col < n - 1) ? matrix[node.row][node.col + 1] : INT_MAX;
        insertMinHeap(minHeap, newMinHeapNode(nextVal, node.row, node.col + 1));
    }

    free(minHeap->heapArray);
    free(minHeap);
    return node.value;
}

int main() {
    int matrix[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int k = 7;
    printf("The %dth smallest element is %d\n", k, kthSmallest(matrix, 4, k));
    return 0;
}
