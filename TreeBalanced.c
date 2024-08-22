// QUESTION: Check if a binary tree is balanced.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Utility function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to check if a tree is balanced
int isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return 1; // An empty tree is balanced

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return 0; // Tree is not balanced

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    // Creating a sample binary tree
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        printf("The binary tree is balanced.\n");
    else
        printf("The binary tree is not balanced.\n");

    return 0;
}
