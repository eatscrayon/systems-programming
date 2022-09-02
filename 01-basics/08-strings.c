#include <stdio.h>
#include <string.h>   // include the C string library

int main() {
    char str1[10];
    char str2[10];
    int len;

    str1[0] = 'h';
    str1[1] = 'i';
    str1[2] = '\0';

    len = strlen(str1);

    printf("%s %d\n", str1, len);  // prints: hi 2

    strcpy(str2, str1);     // copies the contents of str1 to str2
    printf("%s\n", str2);   // prints:  hi

    strcpy(str2, "hello");  // copy the string "hello" to str2
    len = strlen(str2);
    printf("%s has %d chars\n", str2, len);   // prints: hello has 5 chars
}