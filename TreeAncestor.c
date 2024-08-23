//QUESTION: Lowest common ancestor in a binary search tree.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with a given key in BST
struct TreeNode* insert(struct TreeNode* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);

    return node;
}

// Function to find the Lowest Common Ancestor in a BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->val > n1 && root->val > n2)
        return lowestCommonAncestor(root->left, n1, n2);

    // If both n1 and n2 are greater than root, then LCA lies in right
    if (root->val < n1 && root->val < n2)
        return lowestCommonAncestor(root->right, n1, n2);

    // If one key is smaller and one key is greater, this is the LCA
    return root;
}

// Main function to test the code
int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    int n1 = 10, n2 = 14;
    struct TreeNode* lca = lowestCommonAncestor(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->val);
    else
        printf("LCA does not exist\n");

    n1 = 14, n2 = 8;
    lca = lowestCommonAncestor(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->val);
    else
        printf("LCA does not exist\n");

    n1 = 10, n2 = 22;
    lca = lowestCommonAncestor(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->val);
    else
        printf("LCA does not exist\n");

    return 0;
}
