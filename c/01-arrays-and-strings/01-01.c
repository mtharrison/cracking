#include <stdio.h>
#include <string.h>

// This assumes we're looking at a lower-case only word
// and uses a bit vector of 32bits long to store previously
// seen letters

int containsOnlyUniqueCharsBitVector(char * test) {

    __int32_t bv = 0;
    int ptr = 0;

    while (test[ptr] != '\0') {
        char l = test[ptr] % 97;
        if (bv & (1 << l)) {
            return 0;
        }
        bv |= 1 << l;
        ptr++;
    }

    return 1;
}

// This algorithm trades space for time
// It's worst case is 0(n^2) where n is strlen

int containsOnlyUniqueChars(char* test) {

    int ptr1 = 0;
    int ptr2 = 1;
    int len = strlen(test);

    while (ptr1 < (len - 2)) {
        for (int i = ptr2; i < len; i++) {
          if (test[i] == test[ptr1]) {
              return 0;
          }
        }
        ptr1++;
        ptr2 = ptr1 + 1;
    }

    return 1;
} 

int main (int argc, char** argv) {

    char* string1 = "abcdefghijklmnopqrstuvwxyz";
    char* string2 = "quickquick";

    printf("String 1 tests %s\n", containsOnlyUniqueChars(string1) == 1 ? "true" : "false");
    printf("String 2 tests %s\n", containsOnlyUniqueChars(string2) == 1 ? "true" : "false");

    printf("String 1 tests %s\n", containsOnlyUniqueCharsBitVector(string1) == 1 ? "true" : "false");
    printf("String 2 tests %s\n", containsOnlyUniqueCharsBitVector(string2) == 1 ? "true" : "false");
}
