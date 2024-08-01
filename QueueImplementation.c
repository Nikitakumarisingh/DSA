//QUESTION: Implement a queue using stacks.
//CODE:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack, int value) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

void initQueue(Queue *queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(Queue *queue, int value) {
    push(&queue->stack1, value);
}

int dequeue(Queue *queue) {
    if (isStackEmpty(&queue->stack2)) {
        while (!isStackEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }
    if (isStackEmpty(&queue->stack2)) {
        printf("Queue underflow\n");
        return -1;
    }
    return pop(&queue->stack2);
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued: %d\n", dequeue(&queue)); // Should print 10
    printf("Dequeued: %d\n", dequeue(&queue)); // Should print 20

    enqueue(&queue, 40);
    printf("Dequeued: %d\n", dequeue(&queue)); // Should print 30
    printf("Dequeued: %d\n", dequeue(&queue)); // Should print 40

    return 0;
}
