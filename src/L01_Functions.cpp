//
//  L01_Functions.cpp
//  Unit02_lesson01_understanding_functions
//

/*
 Note:

 In this lesson we will understand.
 - function calling itself
 - functions calling each other
 - passing function as argument

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
// Return the sum of the digits in the number
//
// 0 <= number  // positive numbers only
//
int sumOfDigits(int number) {
    
    // 1. terminating condition (base case)
    // single digit, the answer is itself.
    if (number <= 9) {
        return number;
    }
    
    // 2. reducing into smaller problem or
    //    breaking into sub-problems
    //
    // Reducing the problem length by 1
    // and calling for the remaining number.
    int unitsPlaceDigit = number%10;
    int sumOfRemainingDigits = sumOfDigits(n/10);
    
    // 3. combining the sub-problems solutions
    int sum = unitsPlaceDigit + sumOfRemainingDigits;
    
    return sum;
}


//
// now let's add some mystery
//
// 0 <= number  // this mysterious one can't even handle negative numbers
//

int sumOfDigitsMystery(int number) {
    
    // 1. terminating condition (base case)
    // single digit, the answer is itself.
    if (number <= 9) {
        return number;
    }
    
    // 2. reducing into smaller problem or
    //    breaking into sub-problems
    //
    // Reducing the problem length by 1
    // and calling for the remaining number.
    int unitsPlaceDigit = number%10;
    int sumOfRemainingDigits = sumOfDigitsMystery(n/10);
    
    // 3. combining the sub-problems solutions
    int sum = unitsPlaceDigit + sumOfRemainingDigits;
    
    // 4. Let's add mystery
    if (sum > 9) {
        sum = sumOfDigitsMystery(sum);
    }
    
    return sum;
}


//
// To understand the basic concept and notation of Binary Trees
// check: https://github.com/rohinibarla/FOC/raw/master/Lecture%2038.pdf
//

//
// To determine the height of a binary tree
//
int heightOfTree(struct treeNode *root) {
    
    // 1. terminating condition
    if (root == NULL) {
        return 0;
    }
    
    // 2. reducing into smaller problem or
    //    breaking into sub-problems
    //
    // breaking into 2 sub-problems of
    // left sub-tree and
    // right sub-tree
    int rightSubTreeHeight = heightOfTree(root->right);
    int leftSubTreeHeight = heightOfTree(root->left);
    
    // 3. combining the sub-problems solutions
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
// Compare the bellow 2 methods of destroying a Linked List
// These are just written for your reading pleasure
//

// recursive style
//
// since if we release the current head node first
// we cannot use the data inside it
// mainly the head->next value
//
// so first release the remaining linked list
// before releasing the current node.
//


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

int youDoTheWork(int *numbers, int size) {
    
    int result = 0;
    
    if (size > 2) {
        result = firstYouDoThisPart(numbers+2, size-2);
        result = 100 * result + 10 * numbers[1] + numbers[0];
    }
    
    if (size == 2) {
        result = 10 * numbers[1] + numbers[0];
    }
    
    if (size == 1) {
        result = numbers[0];
    }
    
    return result;
}

int firstYouDoThisPart(int *numbers, int size) {
    int partResult = 0;
    if (size > 0) {
        partResult = youDoTheWork(numbers+1, size-1);
        partResult = 10 * partResult + numbers[0];
    }
    return partResult;
}

//
// passing function as argument
//

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
// sort method takes function-as-an-argument
// uses the passed method to sort the list in order
//
// Experiment calling this method (from main.cpp),
// by passing different methods as parameters.
// and see the behaviour
//
void sort(int *numbers, int size, COMPARE isInOrder) {
    
    if (size <= 1) {
        // already sorted
        return;
    }
    
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
// Ref: https://stackoverflow.com/questions/42444024/why-do-we-use-the-term-non-descending-instead-of-ascending-in-sorting-algori
//
void sortNonDescending(int *numbers, int size) {
    sort(numbers, size, isGreater);
}

//
// What is the difference between
// Non-Ascending Vs Descending order?
//
void sortNonAscending(int *numbers, int size) {
    sort(numbers, size, isLesser);
}

static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
