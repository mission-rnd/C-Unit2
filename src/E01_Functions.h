//
//  E01_Functions.h
//  Unit02_Exercise01_Understanding_Functions
//

#ifndef E01_Functions_h
#define E01_Functions_h

#include "BinaryTree.h"

//
// recursive
//
int sumOfNodes(TreeNode *root);
int numberOfNodes(TreeNode *root);
int numberOfLeafNodes(TreeNode *root);


//
// function passing
//
struct people {
    char name[25];
    int age;
    int pinCode;
};

// Returns
// 1 - YES
// 0 - NO
typedef int (*IsInOrderPeopleFunc)(struct people *record1, struct people *record2);

void sort(struct people *peopleRecords[], int size, IsInOrderPeopleFunc isInOrder);

// sort records based on age
void sortByAgeNonAscending(struct people *peopleRecords[], int size);

// sort records based on name
void sortByNameNonDecending(struct people *peopleRecords[], int size);

int outputStringLength(char *format, char ch, int n);

#endif /* E01_Functions_h */
