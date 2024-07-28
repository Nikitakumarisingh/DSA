//QUESTION: Merge two sorted linked lists.
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

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // Dummy node to hang the result on
    struct ListNode dummy;
    // Tail pointer for the result list
    struct ListNode *tail = &dummy;
    dummy.next = NULL;
    
    // While both lists are non-empty
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // One of l1 and l2 can still have remaining nodes
    tail->next = (l1 != NULL) ? l1 : l2;
    
    return dummy.next;
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

int main() {
    // Creating first sorted linked list: 1 -> 3 -> 5
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    struct ListNode* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);
    
    // Merging the two sorted linked lists
    struct ListNode* mergedList = mergeTwoLists(l1, l2);
    
    // Printing the merged linked list
    printf("Merged Linked List:\n");
    printList(mergedList);
    
    return 0;
}
