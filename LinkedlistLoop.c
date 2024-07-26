//QUESTION: Detect a loop in a linked list.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in the linked list
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return 1; // Loop detected
        }
    }
    return 0; // No loop
}

int main() {
    // Creating a linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    // Creating a loop for testing
    head->next->next->next->next->next = head->next->next; // 5 -> 3
    
    if (detectLoop(head)) {
        printf("Loop detected in the linked list.\n");
    } else {
        printf("No loop in the linked list.\n");
    }
    
    return 0;
}
