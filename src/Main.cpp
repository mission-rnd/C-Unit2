/*
Note:
Goal is to understand
 - To become comfortable with
 - functions with variable number of arguments
 - type casting & type definition
 - strings & memory
 - To understand compilation process
    - pre-processor
    - intermediate stages
    - executable format
 - multiple solutions for a problem (principle)

Structure:
The structure of the unit is it contains some lessons and exercises.
In lessons, you will update the test cases (spec) with expected output.
In exercises, you will update the function stubs (src) with functionality.

Actions:
1. You need to fill in the blanks in lesson files under spec project.
 - L01_FunctionsSpec.cpp
 - L02_StringsSpec.cpp
 - L03_TypesSpec.cpp
 - L04_MemorySpec.cpp
 - L05_CompilerSpec.cpp
 By reading the code in lesson files under src project.
 - L01_Functions.cpp
 - L02_Strings.cpp
 - L03_Types.cpp
 - L04_Memory.cpp
 - L05_Compiler.cpp
 And DO NOT modify any functions in the lesson files in src project
 except the comments in three_things_i_learnt() function.

2. You need to implement the function stubs in exercise files in src project.
 - E01_Functions.cpp
 - E02_Strings.cpp
 - E03_Types.cpp
 - E04_Memory.cpp
 - E05_Compiler.cpp
 And DO NOT modify anything in excercise files in spec project
 - E01_FunctionsSpec.cpp
 - E02_StringsSpec.cpp
 - E03_TypesSpec.cpp
 - E04_MemorySpec.cpp
 - E05_CompilerSpec.cpp
 
*/



#include <stdlib.h>
#include <stdio.h>

#include "L01_Functions.h"
#include "L02_String.h"
#include "L03_Types.h"
#include "L04_Memory.h"
#include "L05_Compiler.h"

#include "E01_Functions.h"
#include "E02_String.h"
#include "E03_Types.h"
#include "E04_Memory.h"
#include "E05_Compiler.h"



int main(){
    // Note#1:
    // For testing/debugging a function
    // you can call a function with necessary parameters from here
    // All the necessary header files are included
	printf("Welcome to the playground with memory, string, types and recursion.\n");
	return 0;
}
