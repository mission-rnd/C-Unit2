//
//  L02_Strings.h
//  Unit02_lesson02_understanding_strings
//

#ifndef L02_Strings_h
#define L02_Strings_h

#include <stdlib.h>
#include <stdarg.h>

int stringLength(char *string);
int numberOfFormatSpecifiers(char *format);

void stringMystery(char *name);
void stringMysteryAdd(char *str);
char *stringMysteryCreate(int n);
void numberCharMystery(char *str);
void abcMystery(char *str);

struct customString {
    int length;
    char *str;
};

typedef customString CustomString;

CustomString *addMystery(CustomString one, CustomString two);
char *concatMystery(char *s1, char *s2);

#endif /* L02_Strings_h */
