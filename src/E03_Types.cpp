//
//  E03_Types.cpp
//  Unit02_Exercise03_Understanding_Types
//

#include "E03_Types.h"


//
// add & multiple in base 256
//
// addInBase256 => addBigNumbers
Base256Number *addInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
    
}

Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
    
}

//
// Return
//  1 - yes
//  0 - no
//
int isGreater(Base256Number *pNumber1, Base256Number *pNumber2) {
    
}

void incrementInBase256(Base256Number *pNumber) {
    
}

Base256Number *newNumberInBase256() {
    
}

//
// Note: Each digit in base 256 is saved in reverse order
// e.g:
// ("IPV4: %D oho", {4, [15, 0, 255, 255]})        => "IPV4: 255.255.0.15 oho"
// ("IPV6: %C ohk", {6, [11, 10, 15, 0, 255, 255]) => "IPV6: ff:ff:00:0f:0a:0b ohk"
//

char *printBase256Number(char *format, Base256Number *pNumber) {
    
}

//
// Note: Don't change code of this function
// make the test cases pass, by implementing above functions
//
Base256Number *integerDivisionInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
    Base256Number *pQuotient = newNumberInBase256();
    Base256Number *pNumber = newNumberInBase256();
    while (isGreater(pNumber1, pNumber)) {
        *pNumber = addInBase256(pNumber, pNumber2);
        incrementInBase256(pQuotient);
    }
    return pQuotient;
}

//
// Returns
//  1 - yes
//  0 - no
//
// check if the number is palindrome in base 256
//
int isPalindrome(Base256Number *number) {
    return -99;
}
