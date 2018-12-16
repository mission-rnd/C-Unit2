//
//  E03_Types.cpp
//  Unit02_Exercise03_Understanding_Types
//

#include "E03_Types.h"

//
// Note: The digits in the Base256Number are saved in reverse order.
//

//
// create a new structure for base 256 number
// and initialize with n in base-256
//
Base256Number *newNumberInBase256(int n) {
	int noOfDigits = 0, dummy = n;
	while (dummy > 0){
		dummy /= 256;
		noOfDigits++;
	}
	if (n == 0)noOfDigits = 1;
	Base256Number* result = (Base256Number*)malloc(sizeof(Base256Number));
	result->numberOfDigits = noOfDigits;
	UInt8* digits = (UInt8*)malloc(noOfDigits * sizeof(UInt8));
	dummy = 0;
	if (n == 0){
		digits[0] = 0;
	}
	while (n > 0){
		digits[dummy] = n % 256;
		n /= 256;
		dummy++;
	}
	result->digits = digits;
    return result;
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
		result->numberOfDigits += 1;
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
	if (pNumber1->numberOfDigits > pNumber2->numberOfDigits)	return 1;
	if (pNumber2->numberOfDigits > pNumber1->numberOfDigits)	return 0;
	int i = pNumber1->numberOfDigits - 1;
	while (i > 0){
		if (pNumber1->digits[i] > pNumber2->digits[i])	return 1;
		if (pNumber1->digits[i] < pNumber2->digits[i])	return 0;
		i--;
	}
	return 0;
}

int areEqual(Base256Number *pNumber1, Base256Number *pNumber2) {
	if ((pNumber1->numberOfDigits) != (pNumber2->numberOfDigits))	return 0;
	int numberOfDigits = pNumber1->numberOfDigits;
	for (int i = 0; i < numberOfDigits; i++){
		if ((pNumber1->digits[i]) != (pNumber2->digits[i]))	return 0;
	}
	return 1;
}

void incrementInBase256(Base256Number *pNumber) {
	int start = 0;
	while (1){
		if ((pNumber->digits[start]) == 255){
			if (start == ((pNumber->numberOfDigits) - 1)){
				pNumber->numberOfDigits += 1;
				UInt8* digitsNew = (UInt8*)malloc((pNumber->numberOfDigits)*sizeof(UInt8));
				for (int i = 0; i < (pNumber->numberOfDigits); i++){
					digitsNew[i] = pNumber->digits[i];
				}
				pNumber->digits = digitsNew;
				pNumber->digits[start] = 0;
				pNumber->digits[(start + 1)] = 1;
				return;
			}
			else{
				pNumber->digits[start] += 1;
				start++;
			}
		}
		else{
			pNumber->digits[start] += 1;
			return;
		}
	}
	return;
}

//
// Note: Don't change code of this function
// make the test cases pass, by implementing above functions
//
Base256Number *integerDivisionInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
	if (isGreater(pNumber2, pNumber1))	return 0;
    Base256Number *pQuotient = newNumberInBase256(0);
	Base256Number *pTempNumber = newNumberInBase256(0);
	while (1){
		pTempNumber = addInBase256(pTempNumber, pNumber2);
		if (isGreater(pNumber1, pTempNumber) == 1)	incrementInBase256(pQuotient);
		else break;
	}
	if (areEqual(pNumber1, pTempNumber) == 1){
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
	if (number->numberOfDigits == 1)	return 1;
	int start = 0, end = number->numberOfDigits - 1, mid = number->numberOfDigits / 2;
	while (mid > 0){
		if (number->digits[start] != number->digits[end])	return 0;
		start++; end--; mid--;
	}
    return 1;
}
