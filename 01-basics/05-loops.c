/* C while loop example */
#include <stdio.h>

int main()
{
    // Example 1
    int num, val;

    printf("Enter a value: ");
    scanf("%d", &num);
    if (num < 0)
    {
        num = -num;
    }
    val = 1;
    while (val < num)
    {
        printf("%d\n", val);
        val = val * 2;
    }

    // Example 2

    int i;

    i = 0;
    while (i < 10)
    {
        printf("i is %d\n", i++); // i++: increment i's value after using it
    }

    // Example 3

    int data;

    while (1)
    { // an infinite loop (1 is always true)
        printf("Enter a value beween 0 and 100: ");
        scanf("%d", &data);
        if ((data >= 0) && (data <= 100))
        {
            break; // break out of a loop
        }
        printf("Hey, %d isn't between 0 and 100...try again\n", data);
    }

    printf("The value read in is %d\n", data);

    return 0;
}