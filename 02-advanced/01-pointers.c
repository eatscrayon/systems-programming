#include <stdio.h>

int main()
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

    return 0;
}