#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Not perfect, there's a chance of Buffer overrun here!

char *compress(char *str) {

    int len = strlen(str);
    char *target = malloc(1 + (len * sizeof(char)));

    if (len == 0) {
        return str;
    }

    char curr = *str;
    int count = 0;

    int ptr1 = 0, ptr2 = 0;

    for (;;) {

        char on = *(str + ptr1);
        if (on == 0 || on != curr) {

            if ((ptr2 + 3) >= len) {
                return str;
            }

            *(target + (ptr2++)) = curr;
            char dig[10];
            sprintf(dig, "%d", count);
            int i = 0;
            while(dig[i]) {
                *(target + (ptr2++)) = dig[i];
                i++;
            }

            curr = on;
            count = 0;

            if (on == 0) {
                break;
            }
        }

        count++;
        ptr1++;
    }

    *(target + ptr2 + 1) = '\0';

    return target;
}



int main(int argc, char **argv) {

    char *str = "aaaaaabbbbbbcc";
    char *strcomp = compress(str);
    printf("%s\n", strcomp);

    assert(strcmp(strcomp, "a6b6c2") == 0);

    char *str2 = "aaa";
    char *strcomp2 = compress(str2);
    printf("%s\n", strcomp2);

    assert(strcmp(strcomp2, "aaa") == 0);

    char *str3 = "bbbbbbbbb";
    char *strcomp3 = compress(str3);
    printf("%s\n", strcomp3);

    assert(strcmp(strcomp3, "b9") == 0);

    char *str4 = "aaaabbbbyyyyyyyyyyyyyyyy";
    char *strcomp4 = compress(str4);
    printf("%s\n", strcomp4);

    assert(strcmp(strcomp4, "a4b4y16") == 0);
    return 0;
}
