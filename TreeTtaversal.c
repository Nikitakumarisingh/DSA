//QUESTION: Inorder traversal of a binary tree.
//CODE: 
#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    inorderTraversal(root->left);

    // Visit the root node
    printf("%d ", root->data);

    // Traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    // Create a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Inorder traversal of the binary tree is: ");
    inorderTraversal(root);

    return 0;
}
