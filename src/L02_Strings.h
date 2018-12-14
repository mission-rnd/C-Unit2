//
//  L02_Strings.h
//  Unit02_lesson02_understanding_strings
//

#ifndef L02_Strings_h
#define L02_Strings_h

#include <stdlib.h>
#include <stdarg.h>

int numberOfFormatSpecifiers(char *format);
int stringLength(char *string);

void stringMystery(char *name);

struct customString {
    int length;
    char *str;
}

typedef customString CustomString;

CustomString *addMystery(CustomString one, CustomString two);

// char *generateString(char *format, ...);

#endif /* L02_Strings_h */
