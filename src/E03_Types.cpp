//
//  E03_Types.cpp
//  Unit02_Exercise03_Understanding_Types
//

#include "E03_Types.h"
#include "L02_Strings.h"

//
// Note: The digits in the Base256Number are saved in reverse order.
//

// Note:
// In this file you should not modify 3 functions,
// for which implementation is already given in this file
// The 3 functions are:
// - Base256Number *newNumberInBase256(int n);
// - Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2)
// - Base256Number *integerDivisionInBase256(Base256Number *pNumber, Base256Number *pDiv)


//
// creates a new structure for base 256 number
// and initialize with n in base-256
//
// DON'T MODIFY THE CODE OF THIS FUNCTION
//
Base256Number *newNumberInBase256(int n) {
    int base = 256;
    
    int numberOfDigits = 0;
    int number = n;
    do {
        numberOfDigits++;
        number /= base;
    } while (number > 0);
    
    Base256Number* base256Number = (Base256Number*)malloc(sizeof(Base256Number));
    base256Number->numberOfDigits = numberOfDigits;
    base256Number->digits = (UInt8*)malloc(numberOfDigits * sizeof(UInt8));
    
    for (int digitPos = 0; digitPos < numberOfDigits; digitPos++) {
        base256Number->digits[digitPos] = n % base;
        n /= base;
    }
    
    return base256Number;
}

// Implement the function to
// print the given base 256 number using the format sepcifiers
// %D and %H
//
// For example for 4 digits base 256 number with format specifier
// %D - print digits in the format - 15.0.254.11
// %H - print digits in the format - 0f:00:0a:0b
//
// e.g: like (format, pNumber) => output string
// ("Number (base 256): %D", {4, [11, 254, 0, 15]) => "Number (base 256): 15.0.254.11"
// ("Number (base 256): %H", {4, [11, 254, 0, 15]) => "Number (base 256): 0f:00:fe:0b"
//
// Note: Each digit in base 256 is saved in reverse order
//
char *printBase256Number(char *format, Base256Number *pNumber) {
    return "not-implemented";
}

//
// Returns
//  1 - yes
//  0 - no
//
// check if the base 256 number is palindrome or not
//
int isPalindrome(Base256Number *number) {
    return -99;
}

//
// add in base 256
//
// implement the function to add 2 base 256 numbers
//
Base256Number *addInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
    return NULL;
}

//
// Return
//  1 - when pNumber1 > pNumber2
//  0 - otherwise
//
int isGreater(Base256Number *pNumber1, Base256Number *pNumber2) {
	return -99;
}

//
// Return
//  1 - are equal
//  0 - not equal
//
int areEqual(Base256Number *pNumber1, Base256Number *pNumber2) {
    return -99;
}

//
// increments the given number by 1
//
// Note: Need to reallocate memory for pNumber->digits when needed
//
void incrementInBase256(Base256Number *pNumber) {
    
}

//
// you need make the test cases for these last 2 functions
// pass by implementing the above functions
// - multiplyInBase256
// - integerDivisionInBase256
//
//
// DON'T MODIFY THE CODE OF THIS FUNCTION
//
Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
    Base256Number* result = newNumberInBase256(0);
    Base256Number* count = newNumberInBase256(1);
    Base256Number *pOne = newNumberInBase256(1);
    
    while (!isGreater(count, pNumber2)) {
        result = addInBase256(result, pNumber1);
        count = addInBase256(count, pOne);
    }
    return result;
}

//
// integer division
//
//
// DON'T MODIFY THE CODE OF THIS FUNCTION
//
Base256Number *integerDivisionInBase256(Base256Number *pNumber, Base256Number *pDiv) {
    
    Base256Number *pQuotient = newNumberInBase256(0);
    Base256Number *pTempNumber = newNumberInBase256(0);
    Base256Number *pOne = newNumberInBase256(1);

    if (isGreater(pDiv, pNumber)) {
        return pQuotient;
    }
    
    pTempNumber = addInBase256(pTempNumber, pDiv);
    while(isGreater(pNumber, pTempNumber)) {
        pQuotient = addInBase256(pQuotient, pOne);
        pTempNumber = addInBase256(pTempNumber, pDiv);
    }
    
    if (areEqual(pNumber, pTempNumber)) {
        pQuotient = addInBase256(pQuotient, pOne);
    }
    
    return pQuotient;
}
