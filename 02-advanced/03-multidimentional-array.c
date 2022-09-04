#include <stdio.h>
#include <stdlib.h>

// a C constant definition: COLS is defined to be the value 100
#define COLS  (100)
#define N 3
#define M 4

/*
 * init_matrix: initializes the passed matrix elements to the
 *              product of their index values
 *   m: a 2D array (the column dimension must be 100)
 *   rows: the number of rows in the matrix
 *   return: does not return a value
 */
void init_matrix(int m[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            m[i][j] = i*j;
        }
    }
}

void init2D(int *arr, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i*cols + j] = 65;
        }
    }
}

int main() {
    // Example 1
    // Statically Allocated on the stack
    //
    int matrix[50][COLS];
    int bigger[90][COLS];

    init_matrix(matrix, 50);
    init_matrix(bigger, 90);

    printf("Statically Allocated [10][10]: %d\n",matrix[10][10]);

    // Example 2
    // Dynamically Allocated 2D Arrays on the heap
    // Method 1

    int *two_d_array;    // the type is a pointer to an int (the element type)

    // allocate in a single malloc of N x M int-sized elements:
    two_d_array = malloc(sizeof(int) * N * M);

    if (two_d_array == NULL) {
        printf("ERROR: malloc failed!\n");
        exit(1);
    } else{
        init2D(two_d_array, N, M);
    }
    
    printf("Dynamically Allocated [2*M + 2]: %d\n", two_d_array[2*M + 2]);
    
}