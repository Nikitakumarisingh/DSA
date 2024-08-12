// QUESTION:  Sliding window maximum.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a deque node
struct DequeNode {
    int value;
    int index;
    struct DequeNode *next;
    struct DequeNode *prev;
};

// A structure to represent the deque
struct Deque {
    struct DequeNode *front;
    struct DequeNode *rear;
};

// Function to create a new deque node
struct DequeNode* newDequeNode(int value, int index) {
    struct DequeNode *temp = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    temp->value = value;
    temp->index = index;
    temp->next = temp->prev = NULL;
    return temp;
}

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Function to check if deque is empty
int isEmpty(struct Deque* dq) {
    return dq->front == NULL;
}

// Function to add a new element at the rear
void addRear(struct Deque* dq, int value, int index) {
    struct DequeNode* temp = newDequeNode(value, index);
    if (isEmpty(dq)) {
        dq->front = dq->rear = temp;
        return;
    }
    dq->rear->next = temp;
    temp->prev = dq->rear;
    dq->rear = temp;
}

// Function to remove an element from the front
void removeFront(struct Deque* dq) {
    if (isEmpty(dq)) return;
    struct DequeNode* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
}

// Function to remove an element from the rear
void removeRear(struct Deque* dq) {
    if (isEmpty(dq)) return;
    struct DequeNode* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
}

// Function to get the front element of the deque
struct DequeNode* getFront(struct Deque* dq) {
    if (isEmpty(dq)) return NULL;
    return dq->front;
}

// Function to get the rear element of the deque
struct DequeNode* getRear(struct Deque* dq) {
    if (isEmpty(dq)) return NULL;
    return dq->rear;
}

// Function to find the maximum in each sliding window
void slidingWindowMaximum(int arr[], int n, int k) {
    struct Deque* dq = createDeque();
    
    for (int i = 0; i < n; i++) {
        // Remove elements out of this window
        while (!isEmpty(dq) && getFront(dq)->index <= i - k) {
            removeFront(dq);
        }

        // Remove elements smaller than the currently being added element (from rear)
        while (!isEmpty(dq) && getRear(dq)->value <= arr[i]) {
            removeRear(dq);
        }

        // Add current element at the rear of the deque
        addRear(dq, arr[i], i);

        // Print the maximum of the current window
        if (i >= k - 1) {
            printf("%d ", getFront(dq)->value);
        }
    }

    printf("\n");
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Maximum of each sliding window of size %d:\n", k);
    slidingWindowMaximum(arr, n, k);

    return 0;
}
