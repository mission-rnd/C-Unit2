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

//
// Note: The caller must free the memory returned
//
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

static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
