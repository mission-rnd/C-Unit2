//
//  BinaryTree.cpp

#include "BinaryTree.h"

TreeNode *createTree(int numbers[], int size) {
    
    TreeNode *root;
    TreeNode *node;
  
    root = createNode(numbers[0]);
    for (int i = 1; i < size; i++) {
        node = createNode(numbers[i]);
        insertNodeInTree(root, node);
    }
    
    return root;
}

TreeNode *createNode(int value) {
    TreeNode *node;
    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//
// binary search tree
//
void insertNodeInTree(TreeNode *root, TreeNode *node) {
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
