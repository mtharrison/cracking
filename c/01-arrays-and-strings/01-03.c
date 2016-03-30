#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmpfunc (const void *a, const void *b) {

    return *(char*)a - *(char*)b;
}

bool isPermutationString(char *str1, char *str2) {

    int len = strlen(str1);

    if (strlen(str2) != len) {
        return false;
    }

    // Quick sort the strings in O(n log n) avg time

    qsort(str1, len, sizeof(char), cmpfunc);
    qsort(str2, len, sizeof(char), cmpfunc);

    // Compare the strings in O(n) worst case time

    for (int i = 0; i < len; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv) {

    char str1[] = "boolean";
    char str2[] = "leanoob";
    printf("testing %s against %s\n", str1, str2);
    printf("%s\n", isPermutationString(str1, str2) ? "true" : "false");

    char str3[] = "booleanz";
    char str4[] = "leanoobc";
    printf("testing %s against %s\n", str3, str4);
    printf("%s\n", isPermutationString(str3, str4) ? "true" : "false");

}
