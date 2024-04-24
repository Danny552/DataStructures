#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct node
{
    int key;
    struct node *next;
};

struct node *push(struct node *top, int element){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> key = element;
    newNode -> next = top;
    top = newNode;

    return top;
}

int pop(struct node **top)
{
    struct node *actualNode;
    int element;

    actualNode = *top;
    element = actualNode -> key;
    *top = actualNode -> next;
    free(actualNode);

    return element;
}

void printStack(struct node *top)
{
    struct node *actualNode;
    
    actualNode = top;
    while(actualNode != NULL){
        printf("%d ", actualNode -> key);
        actualNode = actualNode ->next;
    }
    printf ("\n");
}

int stackEmpty(struct node *top)
{
    if(top == NULL)
    return TRUE;
    else
    return FALSE;
}

int main()
{
    struct node *top;
    int operation, element;

    top = NULL;

    while(scanf("%d", &operation) != EOF)
    {
        if(operation == 1)
        {
            scanf("%d", &element);
            top = push(top, element);
            printStack(top);
        }
        else
        {
            if(operation == 2)
            {
                if(stackEmpty(top) != TRUE)
                {
                    element = pop(&top);
                    printf("Element: %d\n", element);
                    printStack(top);
                }
                else
                {
                    printf("The stack is empty.\n");
                }
            }
            else
            {
                printf("Bad use.\n1. Push\n2. Pop\n");
            }
        }
    }
    return 0;
}