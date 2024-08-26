//QUESTION: Maximum path sum in a binary tree.
//CODE:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum path sum in a binary tree
int maxPathSumHelper(struct TreeNode* root, int *maxSum) {
    if (root == NULL) {
        return 0;
    }

    // Recursively find the maximum path sum for the left and right subtrees
    int left = maxPathSumHelper(root->left, maxSum);
    int right = maxPathSumHelper(root->right, maxSum);

    // Calculate the maximum sum through the current node
    int max_single = max(max(left, right) + root->val, root->val);

    // Calculate the maximum sum considering the current node as the root of the path
    int max_top = max(max_single, left + right + root->val);

    // Update the maximum sum found so far
    *maxSum = max(*maxSum, max_top);

    return max_single;
}

// Main function to find the maximum path sum in a binary tree
int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, &maxSum);
    return maxSum;
}

// Example usage
int main() {
    struct TreeNode* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    printf("Maximum path sum is: %d\n", maxPathSum(root));

    return 0;
}
