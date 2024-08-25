//QUESTION: Serialize and deserialize a binary tree.
//CODE:
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to serialize the tree (preorder traversal)
void serialize(struct TreeNode* root, FILE* file) {
    if (root == NULL) {
        fprintf(file, "# ");  // Use # to represent NULL
        return;
    }
    fprintf(file, "%d ", root->data);
    serialize(root->left, file);
    serialize(root->right, file);
}

// Function to deserialize the tree
struct TreeNode* deserialize(FILE* file) {
    char buffer[10];
    if (!fscanf(file, "%s", buffer) || buffer[0] == '#') {
        return NULL;
    }
    struct TreeNode* root = createNode(atoi(buffer));
    root->left = deserialize(file);
    root->right = deserialize(file);
    return root;
}

// Function to print the tree (inorder traversal)
void inorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Serialize the tree to a file
    FILE* file = fopen("tree.txt", "w");
    serialize(root, file);
    fclose(file);

    // Deserialize the tree from the file
    file = fopen("tree.txt", "r");
    struct TreeNode* newRoot = deserialize(file);
    fclose(file);

    // Print the deserialized tree
    printf("Inorder traversal of the deserialized tree:\n");
    inorder(newRoot);

    return 0;
}
