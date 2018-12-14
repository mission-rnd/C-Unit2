//
//  BinaryTree.h


#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

typedef struct treeNode TreeNode;

TreeNode *createNode(int value);
TreeNode *createTree(int numbers[], int size);
void insertNodeInTree(TreeNode *root, TreeNode *node);

#endif /* BinaryTree_h */
