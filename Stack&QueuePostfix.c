//QUESTION: Evaluate a postfix expression.
//CODE:
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack->items[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return stack->items[stack->top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    Stack stack;
    initialize(&stack);
    
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
            // If the character is a digit, push it onto the stack
            push(&stack, expression[i] - '0');
        } else {
            // If the character is an operator, pop two elements from the stack
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
            // Perform the operation and push the result back onto the stack
            switch (expression[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
                default: printf("Invalid operator\n"); exit(1);
            }
        }
    }
    
    // The final result will be the only element left in the stack
    return pop(&stack);
}

int main() {
    char expression[MAX];
    
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    
    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);
    
    return 0;
}
