#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;

    p = malloc(sizeof(int));  // allocate heap memory for storing an int

    if (p != NULL) {
        *p = 65;   // the heap memory p points to gets the value 6
    }
    printf( "Address of p1: %p\n", ( void * )p);
    printf( "Value at p1: %d\n", *p);
    puts(( char * )p);
    free(p);
    p = NULL;
    int i;


    //
    // Example 2
    //

    int s_array[20];
    int *d_array;

    d_array = malloc(sizeof(int) * 20); //Dynamically Allocated Array
    if (d_array == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }

    for (i=0; i < 20; i++) {
        s_array[i] = i;
        d_array[i] = i;
    }

    printf("%d %d \n", s_array[3], d_array[3]);  // prints 3 3

    free(d_array);
    d_array = NULL;
}