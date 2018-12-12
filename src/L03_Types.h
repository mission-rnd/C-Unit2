
//
//  L02_Types.h
//  Unit02_Lesson03_Understanding_Types
//

#ifndef L03_Types_h
#define L03_Types_h

#include <stdlib.h>

struct sumAndProduct {
    int sum;
    int product;
};

typedef struct sumAndProduct SAP;


int computeSumAndProduct01(int number1, int number2);
void computeSumAndProduct02(int number1, int number2, int sum, int product);

SAP computeSumAndProduct11(int number1, int number2);
void computeSumAndProduct21(int number1, int number2, SAP *result);
void computeSumAndProduct31(int number1, int number2, int *pSum, int *pProduct);
int *computeSumAndProduct42(int number1, int number2);
SAP *computeSumAndProduct43(int number1, int number2);

int *computeSumAndProduct42WithMystery(int number1, int number2);
SAP *computeSumAndProduct43WithMystery(int number1, int number2);

#endif /* L03_Types_h */
