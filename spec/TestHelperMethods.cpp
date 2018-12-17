#include "stdafx.h"

// helper method
bool areEqualArrays(int a[], int b[], int size){
	for (int i = 0; i < size; i++){
		if (a[i] != b[i])
			return false;
	}
	return true;
}


//returns true if strings a & b are same.
bool areEqualStrings(char a[], char b[]){
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	if (a[i] == '\0' && b[i] == '\0') {
		return true;
	}

	return false;
}


bool areEqualCharArrays(char a[], char b[], int size) {
    for (int i = 0; i < size; i++){
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool checkBits(int ans, int bits[32]){
	int a = 0;
	for (int i = 0; i < 32; i++)
		a = (a * 2) + bits[i];
	return a == ans;
}

void strcopy(char *a, char *b){
	int i;
	for (i = 0; b[i] != '\0'; i++)
		a[i] = b[i];
	a[i] = b[i];
}


// TODO: strigifyArray

