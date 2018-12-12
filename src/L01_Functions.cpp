//
//  L01_Functions.cpp
//  Unit02_lesson01_understanding_functions
//

/*
 Note:

 In this lesson we will understand.
 - functions calling itself
 - functions calling each other
 - passing function as argument
 - functions with variable number of arguments

 Understand the behaviour by seeing the code (in this file)
 in excution using debugger.
 And fill the blanks in corresponding file: L01_FunctionsSpec.cpp
 under spec project.

 --> Reposting from Unit-1, because this is important.
 Function is the basic building block of any programming language.
 
 This idea of giving freedom for the programmer to add more functionality
 to the language is perhaps the greatest idea in high-level languages.
 
 "The basic langauge can be extended at will."
 Watch this video: https://www.youtube.com/watch?v=UhC20aAl8IM&t=1m5s
 till 5min 30sec.
 
 *****important******
 And DO NOT modify any functions in the lesson files in src project
 except the comments in three_things_i_learnt() function.
*/


#include "L01_Functions.h"


//
// Recursive programs
//

// Note:
// Recursion is itself an interesting mathematical idea
// because of its connection with proof by induction.
//
// Link: https://en.wikipedia.org/wiki/Mathematical_induction
//
// Every recursive program have these 3 parts
//
// 1. terminating condition (base case)
//
// 2. reducing into smaller problem or
//    breaking into sub-problems
//
// 3. combining the sub-problems solutions
//
//
// If you can clearly identify these parts,
// writing recursive programs will be joy.
//


//
// To understand the basic concept and notation of Binary Trees
// check: https://github.com/rohinibarla/FOC/raw/master/Lecture%2038.pdf
//
int heightOfTree(struct treeNode *root) {
    
    // terminating condition
    if (root == NULL) {
        return 0;
    }
    
    // breaking into sub-problems
    int rightSubTreeHeight = heightOfTree(root->right);
    int leftSubTreeHeight = heightOfTree(root->left);
    
    // combining the sub-problems solutions
    int maxSubTreeHeight;
    if(rightSubTreeHeight > leftSubTreeHeight) {
        maxSubTreeHeight = rightSubTreeHeight;
    } else {
        maxSubTreeHeight = leftSubTreeHeight;
    }
    
    // add current level height
    return maxSubTreeHeight + 1;
}


//
// since if we release the current head node first
// we cannot use the data inside it
// mainly the head->next value
//
// so first release the remaining linked list
// before releasing the current node.
//

// TODO:
// use it give a excercise
// typedef void (*FREE_METHOD)(void *);

// TODO: move to header file
struct listNode {
    int data;
    struct listNode *next;
};

void destroyLinkedListV1(struct listNode *head) {
    //
    // 1. terminating condition
    //
    if (head == NULL) {
        return;
    }
    
    // 2. reducing into smaller problem
    // destroying the remaining LL
    destroyLinkedListV1(head->next);
    
    // 3. combining the sub-problems solutions
    // now release this nodes memory
    free(head);
}


//
// non-recursive way
//
//
// since if we release the current head node first
// we cannot use the data inside it
// mainly the head->next value
//
// so first save the next node
// before releasing the current node.
//
void destroyLinkedListV2(struct listNode *head) {
    
    struct listNode *currentNode;
    struct listNode *nextNode;
    
    currentNode = head;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}


//
// functions calling each other
//


//
// passing function as argument
//

//
// returns
// 1 - in correct order, no need to change
// 0 - in reverse order, need to change
//
typedef int (*COMPARE)(int, int);

int isGreater(int a, int b) {
    if(a > b) {
        return 1;
    } else {
        return 0;
    }
}

int isLesser(int a, int b) {
    if(a < b) {
        return 1;
    } else {
        return 0;
    }
}

//
// assumption: size > 1
//
void sort(int *numbers, int size, COMPARE isInOrder) {
    for (int i = 0; i < size-1; i++) {
        if (isInOrder(numbers[i], numbers[i+1]) == 0) {
            // swap numbers
            numbers[i]   = numbers[i] ^ numbers[i+1];
            numbers[i+1] = numbers[i] ^ numbers[i+1];
            numbers[i]   = numbers[i] ^ numbers[i+1];
        }
    }
}


//
// What is the difference between
// Non-Descending Vs Ascending order?
//
void sortNonDescending(int *numbers, int size) {
    sort(numbers, size, isGreater);
}

//
// What is the difference between
// Non-Ascending Vs Descending order?
//
// Ref: https://stackoverflow.com/questions/42444024/why-do-we-use-the-term-non-descending-instead-of-ascending-in-sorting-algori
//
void sortNonAscending(int *numbers, int size) {
    sort(numbers, size, isLesser);
}


//
// functions with variable number of arguments
//

static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
