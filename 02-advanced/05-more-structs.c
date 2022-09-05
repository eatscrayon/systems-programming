/* Copyright (c) 2020, Dive into Systems, LLC (https://diveintosystems.org/)
 *
 * A program reviewing some struct basics
 *  Thinking about variable types is very important.
 *  Note the difference in the effects of the two functions:
 *    checkID: struct passed by value, changing a field value in
 *             parameter does not change the argument's value
 *    changeName: an array passed to function, its parameter
 *                gets the value of its base address, thus
 *                changing an element's value through param changes
 *                the element in the argument (they both refer to
 *                the same set of location in memory).
 */


//Expression  Type               Field Access Syntax
//p1          struct personT     p1.age,  p1.name
//p2          struct personT *   p2->age, p2->name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* define a new struct type (outside function bodies) */
struct studentT {
    char  name[64];
    int   age;
    float gpa;
    int   grad_yr;
};

/* function prototypes */
int checkID(struct studentT s1, int min_age);
void changeName(char *old, char *new);

struct personT {
    char *name;     // for a dynamically allocated string field
    int  age;
};

int example2() {
    struct personT p1, *p2;

    // need to malloc space for the name field:
    p1.name = malloc(sizeof(char) * 8);
    strcpy(p1.name, "Zhichen");
    p1.age = 22;


    // first malloc space for the struct:
    p2 = malloc(sizeof(struct personT));

    // then malloc space for the name field:
    p2->name = malloc(sizeof(char) * 4);
    strcpy(p2->name, "Vic");
    p2->age = 19;
}

int main() {
    int can_vote;
    // declare variables of struct type:
    struct studentT student1, student2;

    // access field values using .
    strcpy(student1.name, "Ruth");
    student1.age = 17;
    student1.gpa = 3.5;
    student1.grad_yr = 2021;

    // structs are lvalues
    student2 = student1;
    strcpy(student2.name, "Frances");
    student2.age = student1.age + 4;

    // passing a struct
    can_vote = checkID(student1, 18);
    printf("%s %d\n", student1.name, can_vote);

    can_vote = checkID(student2, 18);
    printf("%s %d\n", student2.name, can_vote);

    // passing a struct field value
    changeName(student2.name, "Kwame");
    printf("student 2's name is now %s\n", student2.name);

    example2();
    return 0;
}

int checkID(struct studentT s, int min_age) {
    int ret = 1;

    if (s.age < min_age) {
        ret = 0;
        // changes age field IN PARAMETER COPY ONLY
        s.age = min_age + 1;
    }
    return ret;
}

void changeName(char *old, char *new) {
    if ((old == NULL) || (new == NULL)) {
        return;
    }
    strcpy(old,new);
}