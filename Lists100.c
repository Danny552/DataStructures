#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct node 
{
    int key;
    struct node *next;
};

int main(){
    struct node *head, *newnode, *actualnode;
    head = NULL;
    int n = 1000000;
    while (n >= 1){
        newnode = (struct node *) malloc(sizeof(struct node));
        newnode -> key = n;
        newnode -> next = head;
        head = newnode;
        n--;
    }
    actualnode = head;
    while (actualnode != NULL){
        printf ("%d -> ", actualnode -> key);
        actualnode = actualnode -> next;
    }
    printf ("NULL\n");
    actualnode = head;
    while (head != NULL){
        actualnode = head -> next;
        free (head);
        head = actualnode;
    }
    return 0;
}