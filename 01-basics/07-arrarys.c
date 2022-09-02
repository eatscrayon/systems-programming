/* An example C program using an array. */
#include <stdio.h>

void test(int a[], int size) {
    if (size > 3) {
        a[3] = 8;
    }
    size = 2; // changing parameter does NOT change argument
}



int main() {
    int i, size = 0;

    // declare array of 10 ints
    int my_arr[10];

    // set the value of each array element
    for (i = 0; i < 10; i++) {
        my_arr[i] = i;
        size++;
    }

    // set value at position 3 to 100
    my_arr[3] = 100;

    // print the number of array elements
    printf("array of %d items:\n", size);

    // print each element of the array
    for (i = 0; i < 10; i++) {
        printf("%d\n", my_arr[i]);
    }

    int arr[5], n = 5, j;

    for (j = 0; j < n; j++) {
        arr[j] = j;
    }

    printf("%d %d\n", arr[3], n);  // prints: 3 5

    test(arr, n);
    printf("%d %d\n", arr[3], n);  // prints: 8 5

    return 0;
}