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
// Note:
//
// C language does not have String Data Type.
//
// It has a notation, called C String using
// - character array
// - termination character '\0'
//
// And string literals like
// "Insight", "Integrity", "Inspire", "I"
//
// character literals are different from string literals
// 'I' and "I" are not the same
// "I" means {'I', '\0'} - array of 2 characters
//

//
// Number of characters in the string
//
int stringLength(char *string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

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

//
// Note: name's length is atleast 4 characters.
// 
void stringMystery(char *name) {
    int len = stringLength(name);
    name[len/3] = '-';
    name[len/2] = '\0';
    name[len - 1] = '?';
}


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
	str[n / 2] = n / 2 + 'A';
	str[n / 3] = '?';
	str[n] = '\0';
    return str;
}

void numberCharMystery(char *str) {
    *str   = '0';
    str[1] = '0' + 1;
    *(str + 2) = '0' + 2;
    str[3] = '\0';
}

void abcMystery(char *str) {
    *str = '0';
    str = str + 1;
    str[1] = '1';
    str++;
    str[2] = '2';
    str += 1;
    str[3] = '\0';
}

//
// What is the advantange of representing string like this?
//
CustomString *addMystery(CustomString *one, CustomString *two) {
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
// Note: the code is intentionally wrong.
//       Don't fix it, just guess the output.
//
char *concatMystery(char *s1, char *s2) {
    int s1Len = stringLength(s1);
    int s2Len = stringLength(s2);
    char *combinedString = (char *)malloc(s1Len + s2Len + 1);
    
    int targetPos = 0;
    // add the first string
    for (int i = 0; i < s1Len; i++) {
        combinedString[targetPos] = s1[i];
        targetPos += 1;
    }
    
    // add the second string in reverse
    for (int i = s2Len; i > 0; i--) {
        combinedString[targetPos] = s2[i];
        targetPos += 1;
    }
    
    // add the string termination character
    combinedString[targetPos] = '\0';
    
    return combinedString;
}

static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
