//
//  E02_Strings.cpp
//  Unit02_Exercise02_Understanding_Strings
//


/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E02_StringsSpec.cpp file.
 */

#include "E02_Strings.h"
//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(char *pNumber1, char *pNumber2) {
    return 0;
}

//
// sum of 2 non-negative numbers
// pNumber1 and pNumber2 are numbers in string format
// e.g:
// "4", "2" => "6"
// "84", "37" => "121"
// "999", "1" => "1000"
//
// 0 < number of digits < 100
//
char *sum(char *pNumber1, char *pNumber2) {
    return NULL;
}

//
// replicate string n times
//
//e.g:
// "aum ", 3 => "aum aum aum "
// "-integrity-inspire-insight-", 3 => "integrity-inspire-insight--integrity-inspire-insight--integrity-inspire-insight-"
//
char *replicateNTimes(char *mantra, int n) {
    return NULL;
}

//
// repeat character, position times
//
// e.g:
// "mrd" => "mrrddd"
// "btech" => "btteeecccchhhhh"
//
char *repeatPositionTimes(char *word) {
    return NULL;
}

//
// scanf integer implementation
//
int scanfInt(char *input) {
    return 0;
}

//
// scanf float implementation
//
float scanfFloat(char *input) {
    return 0.0;
}

//
// printf implementation
//
// e.g:
// ("%d", 234) => "234"
// ("%3d",  3)  => "  3"
// ("%03d", 7) => "007"
//
char *printfInt(char *format, int n) {
    return NULL;
}

//
// float format print
// e.g:
// ("%.2f", 2.34455f) => "2.34"
// ("%f",0.123456f) => "0.123456"
char *printfFloat(char *format, float n) {
    return NULL;
}

//
// create command line
// Note:
//  - with single space between arguments
//  - no spaces at the end
//
char *getCommandLine(int argc, char *argv[]) {
    return NULL;
}

char *getExecutableName(int argc, char *argv[]) {
    return NULL;
}

//
// remove white spaces in program statement
//
// Note: the characters between double quotes must not change
//
// e.g:
// 'printf (   "compiler first removes unnessary spaces"  )  ;'  =>
// 'printf("compiler first removes unnessary spaces");'
//
void removeSpaces(char *statement) {
    
}


// Return
// 1 - if string t is suffix of s.
// 0 - otherwise

// returns 1 if the string t occurs at the end of the string s, and zero otherwise
int strend(char *s, char *t) {
	return -99;
}
