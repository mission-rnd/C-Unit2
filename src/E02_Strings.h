//
//  E02_Strings.h
//  Unit02_Exercise02_Understanding_Strings
//

#ifndef E02_Strings_h
#define E02_Strings_h

#include <stdlib.h>
#include <stdarg.h>

int sumOfMSDs(char *pNumber1, char *pNumber2);
char *sum(char *pNumber1, char *pNumber2);
char *replicateNTimes(char *mantra, int n);
char *repeatPositionTimes(char *word);
int scanfInt(char *input);
float scanfFloat(char *input);
char *printfInt(char *format, int n);
char *printfFloat(char *format, float n);
char *getCommandLine(int argc, char *argv[]);
char *getExecutableName(int argc, char *argv[]);
void removeSpaces(char *statement);
int strend(char *s, char *t);

#endif /* E02_Strings_h */
