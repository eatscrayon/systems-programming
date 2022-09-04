#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size;
    char str[64];         // statically allocated
    char *new_str = NULL; // for dynamically allocated

    strcpy(str, "Hello");
    size = strlen(str);   // returns 5

    new_str = malloc(sizeof(char) * (size+1)); // need space for '\0'
    if(new_str == NULL) {
        printf("Error: malloc failed!  exiting.\n");
        exit(1);
    }
    strcpy(new_str, str);
    printf("%s %s\n", str, new_str);    // prints "Hello Hello"

    strcat(str, " There");  // concatenate " There" to the end of str
    printf("%s\n", str);    // prints "Hello There"

    free(new_str);  // free malloc'ed space when done
    new_str = NULL;

    return 0;
}