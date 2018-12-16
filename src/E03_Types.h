//
//  E03_Types.h
//  Unit02_Exercise03_Understanding_Types
//

#ifndef E03_Types_h
#define E03_Types_h

#include <stdlib.h>

typedef unsigned char UInt8;

//
// Note:
//  The digits are saved in reverse order
//
// e.g:
//   number 256 will be represented as
//   {2, [0, 1]}  // 1 0 are stored in reverse order
//
struct base256Number {
    unsigned int numberOfDigits;
    UInt8 *digits;
};

typedef struct base256Number Base256Number;

Base256Number *newNumberInBase256(int n);
char *printBase256Number(char *format, Base256Number *pNumber);
int isPalindrome(Base256Number *number);
Base256Number *addInBase256(Base256Number *pNumber1, Base256Number *pNumber2);
Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2);
int isGreater(Base256Number *pNumber1, Base256Number *pNumber2);
int areEqual(Base256Number *pNumber1, Base256Number *pNumber2);
void incrementInBase256(Base256Number *pNumber);
Base256Number *integerDivisionInBase256(Base256Number *pNumber1, Base256Number *pNumber2);

#endif /* E03_Types_h */
