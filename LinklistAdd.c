//QUESTION: Add two numbers represented by linked lists.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = createNode(0);
    struct ListNode* p = l1, * q = l2, * current = dummyHead;
    int carry = 0;
    
    while (p != NULL || q != NULL) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }
    
    if (carry > 0) {
        current->next = createNode(carry);
    }
    
    return dummyHead->next;
}

// Function to print the linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) printf(" -> ");
        node = node->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeList(struct ListNode* node) {
    while (node != NULL) {
        struct ListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

// Main function to test the addTwoNumbers function
int main() {
    // Creating the first linked list: 342 (represented as 2 -> 4 -> 3)
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);
    
    // Creating the second linked list: 465 (represented as 5 -> 6 -> 4)
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);
    
    // Adding the two numbers
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    // Printing the result: 807 (represented as 7 -> 0 -> 8)
    printf("Result: ");
    printList(result);
    
    // Freeing the linked lists
    freeList(l1);
    freeList(l2);
    freeList(result);
    
    return 0;
}
