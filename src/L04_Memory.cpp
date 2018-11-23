//
//  L04_Memory.cpp
//  Unit02_Lesson04_Understanding_Memory
//

// local variable
void makeItNoMystery(char *mystery) {
    mystery = malloc(3);
    mystery[0] = 'N';
    mystery[1] = 'O';
    mystery[2] = '\0';
}

char *makeMystery() {
    char *mystery = malloc(4);
    mystery[0] = 'm';
    mystery[1] = 'y';
    mystery[2] = 's';
    mystery[3] = '\0';
    makeItNoMystery(mystery);
    return mystery;
}

static void three_things_i_learnt() {
    /*
     -
     -
     -
     */
}
