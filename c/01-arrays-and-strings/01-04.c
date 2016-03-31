#include <assert.h>
#include <stdio.h>
#include <string.h>

void percentEncode(char *str, int rl) {

    int numspaces = 0;
    int ptr = -1;

    while (++ptr < rl) {
        if (*(str + ptr) == ' ') {
            numspaces++;
        }
    }
    ptr--;

    while (ptr > 0 && numspaces > 0) {
        char *base = str + ptr;
        if (*(base) == ' ') {
            char *sp = base + (2 * numspaces);
            *(sp - 2) = '%';
            *(sp - 1) = '2';
            *sp = '0';
            numspaces--;
        }
        else {
            *(base + (2 * numspaces)) = *base;
        }
        ptr--;
    }
}

int main(int argc, char **argv) {

    char str[] = "a b  ";
    printf("%s\n", str);
    percentEncode(str, 3);
    printf("%s\n", str);
    assert(strcmp(str, "a%20b") == 0);

    char str2[] = "this is a string      ";
    printf("%s\n", str2);
    percentEncode(str2, 16);
    printf("%s\n", str2);
    assert(strcmp(str2, "this%20is%20a%20string") == 0);
    return 0;
}
