#include <stdio.h>

void simple_examples()
{
    int *ptr;   // stores the memory address of an int (ptr "points to" an int)
    char *cptr; // stores the memory address of a char (cptr "points to" a char)
    int k;
    char ch;

    ptr = &k;   // ptr gets the address of k, pointer "points to" k
    cptr = &ch; // cptr gets the address of ch, pointer "points to" ch

    int *ptr1, *ptr2, x, y;

    x = 8;
    ptr2 = &x; // ptr2 is assigned the address of x
    ptr1 = NULL;
    *ptr2 = 10;    // the memory location ptr2 points to is assigned 10
    y = *ptr2 + 3; // y is assigned what ptr2 points to plus 3
    ptr1 = ptr2;   // ptr1 gets the address value stored in ptr2 (both point to x)
    *ptr1 = 100;
    ptr1 = &y; // change ptr1's value (change what it points to)
    *ptr1 = 80;

}
int change_value(int *input);

int main() {
    int x;
    int y;

    x = 30;
    y = change_value(&x);
    printf("x: %d y: %d\n", x, y);  // prints x: 100 y: 30

    return 0;
}

/*
 * changes the value of the argument
 *     input: a pointer to the value to change
 *     returns: the original value of the argument
 */
int change_value(int *input) {
    int val;

    val = *input; /* val gets the value input points to */

    if (val < 100) {
        *input = 100;  /* the value input points to gets 100 */
    } else {
        *input =  val * 2;
    }

    return val;
}