//
//  E03_Types.cpp
//  Unit02_Exercise03_Understanding_Types
//

#include "E03_Types.h"
#include "L02_Strings.h"

//
// Note: The digits in the Base256Number are saved in reverse order.
//

//
// create a new structure for base 256 number
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

int getNumberOfDigits(int n, int base) {
    int numberOfDigits = 0;
    do {
        numberOfDigits++;
        n /= base;
    } while (n > 0);
    
    return numberOfDigits;
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
    
    // get the format specifier
    char formatSpecifier;
    int formatSpecifierPos = 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            formatSpecifierPos = i;
            formatSpecifier = format[i+1];
        }
    }
    
    // find the result string length
    int totalStringLength = stringLength(format) - 2; // remove fomat specifier characters
    
    if (formatSpecifier == 'D') {
        for (int i = 0; i < pNumber->numberOfDigits; i++) {
            totalStringLength += getNumberOfDigits(pNumber->digits[i], 10);
        }
    } else {
        totalStringLength += 2 * pNumber->numberOfDigits;
    }
    
    totalStringLength += pNumber->numberOfDigits - 1;
    
    
    // reserve memory
    char *formatString = (char *)malloc(totalStringLength+1);
    formatString[totalStringLength] = '\0';
    
    // copy till formatSpecifierPos-1
    for (int i = 0; i < formatSpecifierPos; i++) {
        formatString[i] = format[i];
    }
    
    int currentPos = formatSpecifierPos;
    // fill the number in the given format
    int numberOfDigits = pNumber->numberOfDigits;
    
    char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = numberOfDigits - 1 ; i >= 0; i--) {
        int b256Digit = pNumber->digits[i];
        if(formatSpecifier == 'D') {
            int nDigits = getNumberOfDigits(b256Digit, 10);
            for (int pos = nDigits - 1; pos >= 0 ; pos--) {
                formatString[currentPos + pos] = hex[b256Digit % 10]; // (or) '0' + b256Digit % 10
                b256Digit /= 10;
            }
            currentPos += nDigits;
            formatString[currentPos] = '.';
        } else {
            formatString[currentPos] = hex[b256Digit/16];
            formatString[currentPos + 1] = hex[b256Digit%16];
            currentPos += 2;
            formatString[currentPos] = ':';
        }
        currentPos++;
    }
    currentPos--;
    
    // copy the string after format specifier
    for (int i = formatSpecifierPos + 2; format[i] != '\0'; i++) {
        formatString[currentPos] = format[i];
        currentPos++;
    }
    
    // set the terminations char
    formatString[totalStringLength] = '\0';
    
    return formatString;
//    return "not-implemented";
}

//
// Returns
//  1 - yes
//  0 - no
//
// check if the base 256 number is palindrome or not
//
int isPalindrome(Base256Number *number) {
    for (int i = 0; i < number->numberOfDigits/2; i++) {
        if (number->digits[i] != number->digits[(number->numberOfDigits-1)-i]) {
            return 0;
        }
    }
    return 1;
//    return -99;
}


//
// add in base 256
//
// implement the function to add 2 base 256 numbers
//
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



//
// Return
//  1 - yes
//  0 - no
//
int isGreater(Base256Number *pNumber1, Base256Number *pNumber2) {
    
    if (pNumber1->numberOfDigits > pNumber2->numberOfDigits) {
        return 1;
    }
    if (pNumber2->numberOfDigits > pNumber1->numberOfDigits) {
        return 0;
    }
    
	int i = pNumber1->numberOfDigits - 1;
	while (i >= 0){
        if (pNumber1->digits[i] > pNumber2->digits[i]) {
            return 1;
        }
        if (pNumber2->digits[i] > pNumber1->digits[i]) {
            return 0;
        }
		i--;
	}
	return 0;
}

//
// Return
//  1 - yes
//  0 - no
//
int areEqual(Base256Number *pNumber1, Base256Number *pNumber2) {
    if ((pNumber1->numberOfDigits) != (pNumber2->numberOfDigits)) {
        return 0;
    }
	int numberOfDigits = pNumber1->numberOfDigits;
	for (int i = 0; i < numberOfDigits; i++){
        if ((pNumber1->digits[i]) != (pNumber2->digits[i])) {
            return 0;
        }
	}
	return 1;
}

//
// increments the given number by 1
//
void incrementInBase256(Base256Number *pNumber) {
    
    // Add 1 to and keep the carry
    // after the loop if carry is there, re-allocate and save the carry
    
    unsigned int carry = 1, sum = 0;
    for (int i = 0; i < pNumber->numberOfDigits; i++) {
        sum = pNumber->digits[i] + carry;
        pNumber->digits[i] = sum % 256;
        carry = sum/256;
    }
    
    if (carry > 0) {
        pNumber->digits = (UInt8 *)realloc(pNumber->digits, pNumber->numberOfDigits+1);
        pNumber->digits[pNumber->numberOfDigits] = carry;
        pNumber->numberOfDigits += 1;
    }
}

//
// Note: Don't modify code of these last 2 functions
// - multiplyInBase256
// - integerDivisionInBase256
//
// you need make the test cases for these functions
// pass by implementing the above functions
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
