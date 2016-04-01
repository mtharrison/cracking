#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *compress(char *str) {

    int len = strlen(str);
    char* target = malloc(1 + (len * sizeof(char)));

    if (len == 0) {
        strcpy(target, str);
        return target;
    }

    char curr = *str;

    int count = 0, ptr1 = 0, ptr2 = 0;

    for (;;) {

        char on = *(str + ptr1);
        if (on == 0 || on != curr) {

            if ((ptr2 + 3) >= len) {
                strcpy(target, str);
                return target;
            }

            *(target + (ptr2++)) = curr;
            char dig[2];
            sprintf(dig, "%d", count);
            *(target + (ptr2++)) = dig[0];
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
    return 0;
}
