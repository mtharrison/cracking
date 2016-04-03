#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool isSubstring(char *str1, char *str2) {

    return strstr(str1, str2) != NULL;
}

// This is an in-place check
// We can do it more elegantly by checking is isSubstring(s1s1, s2)
// but that requires allocating a new string of size s1 * 2

bool isRotation(char *str1, char *str2) {

    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    char *p1 = str1;
    char *p2 = str2;

    while (*p2) {
        if (*p2 == *p1) {
            p1++;
            p2++;
        }
        else {
            if (p1 == str1) {
                p2++;
            }
            p1 = str1;
        }
    }

    return isSubstring(str2, p1);
}

int main(int argc, char **argv) {

    char *str1 = "Waterbottle";
    char *str2 = "erbottleWat";

    assert(isRotation(str1, str2));

    str1 = "Waterbottle";
    str2 = "Waterbottle";

    assert(isRotation(str1, str2));

    str1 = "erbottleWat";
    str2 = "Waterbottle";

    assert(isRotation(str1, str2));

    str1 = "erbottleWate";
    str2 = "Waterbottle";

    assert(!isRotation(str1, str2));

    str1 = "erboterbottle";
    str2 = "erbottleerbot";

    assert(isRotation(str1, str2));

    return 0;
}
