//
//  L02_Types.cpp
//  Unit02_Lesson03_Understanding_Types
//

/*
 Note:
 
 In this lesson we will understand.
 - function returning more than one value
 - defining type using typedef and
 - type casting

*/

//
// Note: The code is written with intension
// to make you read the code carefully.
//

#include "L03_Types.h"


//
// function to compute and return sum & product of two numbers
//
int computeSumAndProduct01(int number1, int number2) {
    int sum, product;
    sum = number1 + number2;
    product = number1 * number2;
    return sum;
    return product;
}

//
// function to compute sum & product of two numbers
// and save them in the addresses of the passed variables
//
void computeSumAndProduct02(int number1, int number2, int sum, int product) {
    int *pSum = &sum;
    int *pProduct = &product;
    *pSum = number1 + number2;
    *pProduct = number1 * number2;
}

SAP computeSumAndProduct11(int number1, int number2) {
    SAP sp;
    sp.sum = number1 + number1 + number1;
    sp.product = (number2 << 4) % number1;
    return sp;
}

void computeSumAndProduct21(int number1, int number2, SAP *result) {
    result->sum = number1 * number2 - number1;
    result->product = number1 + number2/number1;
}

void computeSumAndProduct31(int number1, int number2, int *pSum, int *pProduct) {
    *pSum = (number1 & 0x00FF) | (number2 & 0xFF00);
    *pProduct = (number1 & 0x00FF) ^ (number2 & 0xFF00);
}

int *computeSumAndProduct42(int number1, int number2) {
    int *result = (int *)malloc(8);
    result[0] = (number2 << number1) & number1;
    result[1] = number1 ^ number2;
    return result;
}


SAP *computeSumAndProduct43(int number1, int number2) {
    SAP *result = (SAP *)malloc(sizeof(SAP));
    result->sum = (number2 << number1) & number1;
    result->product = number1 ^ number2;
    return result;
}

//
// solve these with type casting mystery
//
int *computeSumAndProduct42WithMystery(int number1, int number2) {
    SAP *result = (SAP *)malloc(sizeof(SAP));
    result->sum = (number2 << number1) & number1;
    result->product = number1 ^ number2;
    return (int *)result;
}

SAP *computeSumAndProduct43WithMystery(int number1, int number2) {
    int *result = (int *)malloc(2*sizeof(int));
    result[0] = (number2 << number1) & number1;
    result[1] = number1 ^ number2;
    return (SAP *)result;
}


//
// Write what you have learned with the above
// examples?
//
static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
