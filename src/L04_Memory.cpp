//
//  L04_Memory.cpp
//  Unit02_Lesson04_Understanding_Memory
//

#include "L04_Memory.h"

// local variable
void makeItNoMystery(char *mystery) {
    mystery = (char *)malloc(3);
    mystery[0] = 'N';
    mystery[1] = 'O';
    mystery[2] = '\0';
}

char *makeMystery() {
    char *mystery = (char *)malloc(4);
    mystery[0] = 'm';
    mystery[1] = 'y';
    mystery[2] = 's';
    mystery[3] = '\0';
    makeItNoMystery(mystery);
    return mystery;
}

int memoryFirstByte(int n) {
    char *result = (char *)&n;
    int m;
    m = result[0];
    return m;
}

int memoryLastByte(int n) {
    char *result = (char *)&n;
    int m;
    m = result[3];
    return m;
}

int ohISee() {
    char *str = "Oh I See";
    int m = str[2] + str[4];
    return m;
}

//
// Write what you have learned with the above
// examples?
//
static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
