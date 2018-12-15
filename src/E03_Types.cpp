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
	if (pNumber1 == NULL)return pNumber2;
	if (pNumber2 == NULL)return pNumber1;
	if ((pNumber1->numberOfDigits == 0) || (pNumber2->numberOfDigits == 0))	return NULL;
	struct base256Number* result = (struct base256Number*)malloc(sizeof(base256Number));
	if (pNumber1->numberOfDigits > pNumber2->numberOfDigits){
		result->numberOfDigits = pNumber1->numberOfDigits;
	}
	else{
		result->numberOfDigits = pNumber2->numberOfDigits;
	}
	UInt8 *digits = (UInt8*)malloc((result->numberOfDigits)*sizeof(UInt8));
	UInt8 carry = 0;
	int i = 0, current_sum = 0;
	while ((i < pNumber1->numberOfDigits) && (i < pNumber2->numberOfDigits)){
		current_sum = pNumber1->digits[i] + pNumber2->digits[i] + carry;
		digits[i] = current_sum % 255;
		carry = current_sum / 255;
		i++;
	}
	if (pNumber1->numberOfDigits > pNumber2->numberOfDigits){
		while (i < pNumber1->numberOfDigits){
			current_sum = pNumber1->digits[i] + carry;
			digits[i] = current_sum % 255;
			carry = current_sum / 255;
			i++;
		}
	}
	else if (pNumber2->numberOfDigits > pNumber1->numberOfDigits){
		while (i < pNumber2->numberOfDigits){
			current_sum = pNumber2->digits[i] + carry;
			digits[i] = current_sum % 255;
			carry = current_sum / 255;
			i++;
		}
	}
	if (carry > 0){
		result->numberOfDigits++;
		digits = (UInt8*)realloc(digits, sizeof(UInt8) * (result->numberOfDigits));
		digits[i] = carry;
	}
	result->digits = digits;
    return result;
}

Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
	if ((pNumber1 == NULL)||(pNumber2==NULL))return NULL;
	if ((pNumber1->numberOfDigits == 0) || (pNumber2->numberOfDigits == 0))	return NULL;
	struct base256Number* result = (struct base256Number*)malloc(sizeof(base256Number));
	result->numberOfDigits = pNumber1->numberOfDigits + pNumber2->numberOfDigits;
	UInt8 *digits = (UInt8*)malloc((result->numberOfDigits)*sizeof(UInt8));
    return NULL;
}

//
// Return
//  1 - yes
//  0 - no
//
int isGreater(Base256Number *pNumber1, Base256Number *pNumber2) {
	return -1;
}

void incrementInBase256(Base256Number *pNumber) {
    
}

Base256Number *newNumberInBase256() {
    return NULL;
}

//
// Note: Each digit in base 256 is saved in reverse order
// e.g:
// ("IPV4: %D oho", {4, [15, 0, 255, 255]})        => "IPV4: 255.255.0.15 oho"
// ("IPV6: %C ohk", {6, [11, 10, 15, 0, 255, 255]) => "IPV6: ff:ff:00:0f:0a:0b ohk"
//

char *printBase256Number(char *format, Base256Number *pNumber) {
    return NULL;
}

//
// Note: Don't change code of this function
// make the test cases pass, by implementing above functions
//
Base256Number *integerDivisionInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
    Base256Number *pQuotient = newNumberInBase256();
    Base256Number *pNumber = newNumberInBase256();
    while (isGreater(pNumber1, pNumber)) {
        pNumber = addInBase256(pNumber, pNumber2);
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
