//QUESTION: Remove the N-th node from the end of a linked list.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to remove the N-th node from the end of the list
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to simplify edge cases
    struct ListNode* dummy = createNode(0);
    dummy->next = head;
    struct ListNode *first = dummy, *second = dummy;

    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    // Move first to the end, maintaining the gap
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // Remove the N-th node
    struct ListNode* nodeToRemove = second->next;
    second->next = nodeToRemove->next;
    free(nodeToRemove);

    // Get the new head
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Creating a linked list for demonstration
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    int n = 2; // Remove the 2nd node from the end
    head = removeNthFromEnd(head, n);

    printf("List after removing %d-th node from the end:\n", n);
    printList(head);

    // Free the list
    freeList(head);

    return 0;
}
