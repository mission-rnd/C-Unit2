//
//  L01_Functions.cpp
//  Unit02_lesson01_understanding_functions
//

/*
 Note:

 In this lesson we will understand.
 - functions with variable number of arguments
 - functions calling each other
 - functions calling itself 
 - function returning more than one value 

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


// move these to spec
int sum = 0, product = 0;
sum, product = computeSumAndProduct01(2, 0);
sum, product = computeSumAndProduct01(2, 4);
sum, product = computeSumAndProduct01(2, 8);

int computeSumAndProduct01(int number1, int number2) {
    int sum, product;
    sum = number1 + number2;
    product = number1 * number2;
    return sum;
    return product;
}

// move these to spec
int sum = 0, product = 0;
computeSumAndProduct02(2, 0, sum, product);
computeSumAndProduct02(2, 4, sum, product);
computeSumAndProduct02(2, 8, sum, product);
void computeSumAndProduct02(int number1, int number2, int sum, int product) {
    int *pSum = &sum;
    int *pProduct = &product;
    *pSum = number1 + number2;
    *pProduct = number1 * number2;
}



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
int heightOfTree(struct node *root) {
    
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
// so first release the next node
// before releasing the current node.
//


void destroyLinkedListV1(struct ListNode *head, void freeMethod) {
    //
    // 1. terminating condition
    //
    if (head == NULL) {
        return;
    }
    
    // 2. reducing into smaller problem
    // destroying the remaining LL
    destroyLinkedList(head->next);
    
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
void destroyLinkedListV2(struct ListNode *head) {
    
    struct ListNode *currentNode;
    struct ListNode *nextNode;
    
    currentNode = head;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
}


static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
