//
//  BinaryTree.h


#ifndef BinaryTree_h
#define BinaryTree_h

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value);
struct Node *createTree();
void insertNodeInTree(struct Node *root, struct Node *node);

#endif /* BinaryTree_h */
