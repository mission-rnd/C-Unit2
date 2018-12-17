//
//  E01_Functions.cpp
//  Unit02_Exercise01_Understanding_Functions
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_FunctionsSpec.cpp file.
 
 */

#include "E01_Functions.h"
#include "L02_Strings.h"

int sumOfNodes(TreeNode *root) {
    
    // 1. terminating condition (base case)
    if (root == NULL) {
        return 0;
    }
    
    //
    // 2. reducing into smaller problem or
    //    breaking into sub-problems
    int sumOfNodesLeftSubTree = sumOfNodes(root->left);
    int sumOfNodesRightSubTree = sumOfNodes(root->right);
    
    //
    // 3. combining the sub-problems solutions
    //
    int sum = root->data + sumOfNodesLeftSubTree + sumOfNodesRightSubTree;
    return sum;
}

int numberOfNodes(TreeNode *root) {
    // 1. terminating condition (base case)
    if (root == NULL) {
        return 0;
    }
    
    //
    // 2. reducing into smaller problem or
    //    breaking into sub-problems
    int leftSubTreeNodesCount = numberOfNodes(root->left);
    int rightSubTreeNodesCount = numberOfNodes(root->right);
    
    //
    // 3. combining the sub-problems solutions
    //
    int count = leftSubTreeNodesCount + rightSubTreeNodesCount + 1; // for current node
    return count;
}

int numberOfLeafNodes(TreeNode *root) {

    // just in case he calles with NULL
    if (root == NULL) {
        return 0;
    }
    
    // 1. terminating condition (base case)
    if (root->right == NULL && root->left == NULL) {
        return 1;
    }
    
    //
    // 2. reducing into smaller problem or
    //    breaking into sub-problems
    int leftSubTreeLeafCount = 0;
    if (root->left != NULL) {
        leftSubTreeLeafCount = numberOfLeafNodes(root->left);
    }
    
    int rightSubTreeLeafCount = 0;
    if (root->right != NULL) {
        rightSubTreeLeafCount = numberOfLeafNodes(root->right);
    }
    
    //
    // 3. combining the sub-problems solutions
    //
    int count = leftSubTreeLeafCount + rightSubTreeLeafCount;
    return count;
}


//
// Note: don't change this function code
//
// sort records, based on specific parameters.
//
void sort(struct people *peopleRecords[], int size, IsInOrderPeopleFunc isInOrder) {
    // implement simple sorting method
    int positionToReplace;
    for (int i = 0; i < size - 1; i++) {
        positionToReplace = i;
        for (int j = i+1; j < size; j++) {
            if(!isInOrder(peopleRecords[positionToReplace], peopleRecords[j])) {
                positionToReplace = j;
            }
        }
        // swap the records in position: i & positionToReplace
        struct people *temp = peopleRecords[i];
        peopleRecords[i] = peopleRecords[positionToReplace];
        peopleRecords[positionToReplace] = temp;
    }
}

//
// write this method to make the sorting by age non-ascending order work
//
// Returns
// 1 - yes non-ascending order
// 0 - otherwise
int isNonAscendingByAge(struct people *record1, struct people *record2) {
    if (record1->age >= record2->age) {
        return 1;
    }
    return 0;
}

// Note: don't change this function code
// sort records based on age non-ascending order
void sortByAgeNonAscending(struct people *peopleRecords[], int size) {
    // create isNonAscendingByAge function and call sort method
    sort(peopleRecords, size, isNonAscendingByAge);
}


//
// write this method to make the sorting by name non-decending order work
//
// Returns
// 1 - yes non-decending order
// 0 - otherwise
int isNonDecendingByName(struct people *record1, struct people *record2) {
    // record1 name must be less or equal to record2
    char *name1 = record1->name;
    char *name2 = record2->name;
    
    int i;
    for (i = 0; name1[i] != '\0' && name2[i] != 0; i++) {
        if (name1[i] < name2[i]) {
            return 1;
        }
        if (name1[i] > name2[i]) {
            return 0;
        }
    }
    
    // both are same till this point one or both of them reached end
    if (name1[i] == '\0') {
        // means first one ended.
        // it means it less or equal.
        // less - in case other name2 did not end.
        // equal - in case other name2 did end.
        return 1;
    }
    
    if (name2[i] == '\0') {
        // means this is less than name1
        return 0;
    }
}

// Note: don't change this function code
// sort records based on name non-decending order
void sortByNameNonDecending(struct people *peopleRecords[], int size) {
    // create isNonDecendingByName function and call sort method
    sort(peopleRecords, size, isNonDecendingByName);
}

//int stringLength(char *str) {
//    int len = 0;
//    while (str[len] != '\0') {
//        len++;
//    }
//    return len;
//}

int numberOfDigits(int n) {
    int digits = 0;
    do {
        n /= 10;
        digits++;
    } while (n > 0);
    return digits;
}

//
// The 'format' will contain only %c and %d, format specifiers
// rest are just characters
//

// Returns
//   number of characters in the output string
//   when printed with format and the two arguments
//
// e.g:
// ("Hai %c 00%d", 'b', 7) => 9
//  since "Hai b 007" contains 9 characters
int outputStringLength(char *format, char ch, int n) {
    int outLength = stringLength(format) - 4; // removed for format specifiers
    outLength += numberOfDigits(n) + 1; // for number and character
    return outLength;
}
