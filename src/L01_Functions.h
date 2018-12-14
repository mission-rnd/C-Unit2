//
//  L01_Functions.h
//  Unit02_lesson01_understanding_functions
//

#ifndef L01_Functions_h
#define L01_Functions_h

#include <stdarg.h>
#include "BinaryTree.h"

struct listNode {
    int data;
    struct listNode *next;
};

int heightOfTree(struct treeNode *root);
void destroyLinkedListV1(struct listNode *head);
void destroyLinkedListV2(struct listNode *head);

int youDoTheWork(int *numbers, int size);
int firstYouDoThisPart(int *numbers, int size);

void sortNonDescending(int *numbers, int size);
void sortNonAscending(int *numbers, int size);

int multiplyAll(int numbersCount, ...);

#endif /* L01_Functions_h */
