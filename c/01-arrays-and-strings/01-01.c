#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "BitVector.h"

bool containsOnlyUniqueChars(char * test) {

    // Get a bitvector of 255 bits (for entire ascii charset)

    BitVector *v = BitVectorNew(255);

    int pos = 0;
    char l;

    while ((l = *(test + pos))) {

        if (BitVectorGet(v, l)) {
            printf("Seen letter %c more than once at position %d\n", l, pos);
            return false;
        }
        BitVectorSet(v, l);
        pos++;
    }

    free(v);

    return true;
}

int main (int argc, char** argv) {

    char* string1 = "abcdefghijklmnopqrstuvwxyz";
    char* string2 = "quickquick";

    printf("String 1 tests %s\n", containsOnlyUniqueChars(string1) ? "true" : "false");
    printf("String 2 tests %s\n", containsOnlyUniqueChars(string2) ? "true" : "false");
}
