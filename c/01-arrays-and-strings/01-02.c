#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    
    char *right = str + (strlen(str) - 1);
    
    while (right > str) {
        
        char temp = *str;
        *str = *right;
        *right = temp;
        str++;
        right--;
    }
}

int main(int argc, char **argv) {
    
    char str[] = "This is a string";
    printf("Original string is: \"%s\"\n", str);
    reverse(str);
    printf("Reversed string is: \"%s\"\n", str);
    
    
    char str2[] = "Yet another string you need to reverse";
    printf("Original string is: \"%s\"\n", str2);
    reverse(str2);
    printf("Reversed string is: \"%s\"\n", str2);
}
