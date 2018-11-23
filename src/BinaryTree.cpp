//
//  BinaryTree.cpp

#include "BinaryTree.h"

struct Node *createTree(int numbers[], int size) {
    
    struct Node *root;
    struct Node *node;
    
    root = createNode(numbers[0]);
    for (int i = 1; i < size; i++) {
        node = createNode(numbers[i]);
        insertNodeInTree(root, node);
    }
    
    return root;
}


struct Node *createNode(int value) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//
// binary search tree
//
void insertNodeInTree(struct Node *root, struct Node *node) {
    if (node->data > root->data) {
        // insert in right sub-tree
        
        if(root->right != NULL) {
            // right sub-tree exists
            return insertNodeInTree(root->right, node);
        }
        
        // there is no right sub-tree
        root->right = node;
        
    } else {
        // insert in left sub-tree
        if (root->left != NULL) {
            // left sub-tree exists
            return insertNodeInTree(root->left, node);
        }
        
        // there is no left sub-tree
        root->left = node;
    }
}
