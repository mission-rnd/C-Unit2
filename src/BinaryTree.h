//
//  BinaryTree.h


#ifndef BinaryTree_h
#define BinaryTree_h

struct treeNode {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct treeNode TreeNode;

TreeNode *createNode(int value);
TreeNode *createTree();
void insertNodeInTree(TreeNode *root, TreeNode *node);

#endif /* BinaryTree_h */
