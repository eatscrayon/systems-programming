#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;           // used to store a list element's data value
    struct node *next;  // used to point to the next node in the list
};

int main(){
    struct node *head, *temp;
    int i;

    head = NULL;  // an empty linked list

    head = malloc(sizeof(struct node));  // allocate a node
    if (head == NULL) {
        printf("Error malloc\n");
        exit(1);
    }
    head->data = 10;    // set the data field
    head->next = NULL;  // set next to NULL (there is no next element)

    // add 2 more nodes to the head of the list:
    for (i = 0; i < 2; i++) {
        temp = malloc(sizeof(struct node));  // allocate a node
        if (temp == NULL) {
            printf("Error malloc\n");
            exit(1);
        }
        temp->data = i;     // set data field
        temp->next = head;  // set next to point to current first node
        head = temp;        // change head to point to newly added node
    }
}