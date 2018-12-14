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
int sumOfNodes(struct Node *root);
int numberOfNodes(struct Node *root);
int numberOfLeafNodes(struct Node *root);


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

void sort(struct people *peopleRecords, int size, IsInOrderPeopleFunc isInOrder);

// sort records based on age
void sortByAge(struct people *peopleRecords, int size);

// sort records based on name
void sortByName(struct people *peopleRecords, int size);


#endif /* E01_Functions_h */
