//
//  L02_String.cpp
//  Unit02_lesson02_understanding_strings
//

//
// Strings
//

/*
 
 Note:
 Strings are overwelmingly the majority of any application.
 
 You read the code in this file and understand the behaviour.
 And fill the blanks in corresponding file: L02_StringsSpec.cpp under spec project.
 
 *****important******
 And DO NOT modify any functions in the lesson files in src project
 except the comments in three_things_i_learnt() function.
 */

#include "L02_Strings.h"
//
// assumption: handles simple printf format specifiers
//
int numberOfFormatSpecifiers(char *format) {
    int count = 0;
    while (*format != '\0' /* not end of string */) {
        if (*format == '%') {
            count++;
        }
        format++;
    }
    return count;
}

int stringLength(char *string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}


// TODO: give all test cases with strings of length 4 and above.
void stringMystery(char *name) {
    int len = stringLength(name);
    name[len/3] = '-';
    name[len/2] = '\0';
    name[len - 1] = '?';
}

// give string of length 12 to 16
// but update only the first 4 characters
// "impart confidence"
// "jumpToMax"
// "digDeeper"
// "ThinkBigAndBigger"
void stringMysteryAdd(char *str) {
    int len = stringLength(str);
    for (int i = 0; i < 5; i++) {
        str[i] = str[i] + i;
    }
}

// give n
// 2, 4, 8, 9.
char *stringMysteryCreate(int n) {
    char *str = (char *)malloc(n+1);
    for (int i = n-1; i >=0; i--) {
        str[i] = i + '0';
    }
    str[n/2] = n/2 + 'A';
    str[n/3] = '?'
    str[n] = '\0';
    return str;
}

//
// What is the advantange of representing string like this?
//
CustomString *addMystery(CustomString one, CustomString two) {
    CustomString *sum = (CustomString *)malloc(sizeof(CustomString));
    sum->length = (2 * one->length) + two->length;
    sum->str = (char *)malloc(sum->length);
    int targetPosition = 0;
    for (int i = 0; i < one->length; i++) {
        sum->str[targetPosition] = one->str[i];
        targetPosition += 1;
    }
    
    for (int i = 0; i < two->length; i++) {
        sum->str[targetPosition] = two->str[i];
        targetPosition += 1;
    }
    
    for (int i = 0; i < one->length; i++) {
        sum->str[targetPosition] = one->str[i];
        targetPosition += 1;
    }
    return sum;
}


//
// Note: The caller must free the memory returned
//
/*
char *generateString(char *format, ...) {
    
    int length = stringLength(format);
    
    // duplicate string
    char *resultString = (char *)malloc(length * sizeof(char));
    
    int nFormatSpecifiers = numberOfFormatSpecifiers(format);
    
    va_list variableArgumentList;
    
    va_start(variableArgumentList, nFormatSpecifiers);
    
    int charPosition = 0;
    int number = 0;
    char ch;
    while (format[charPosition] != '\0') {
        if (format[charPosition] == '%') {
            switch (format[charPosition+1]) {
                case 'd':
                    // replace %d with 2 digits of given number
                    number = va_arg(variableArgumentList, int);
                    resultString[charPosition] = (number/100)%10 + '0';
                    resultString[charPosition+1] = number%10 + '0';
                    break;
                case 'c':
                    // replace %d with 2 times of given character
                    ch = va_arg(variableArgumentList, char);
                    resultString[charPosition] = ch;
                    resultString[charPosition+1] = ch;
                    break;
                    
                default:
                    break;
            }
            
            // to skip the %c or %d
            charPosition++;
        }
        charPosition++;
    }
    
    // set the termination character
    resultString[charPosition] = '\0';
    
    va_end(variableArgumentList);
    
    return resultString;
}
*/
static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
