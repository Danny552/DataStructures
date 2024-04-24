#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int key;
    struct node *next;
};

struct node *insertElementInAscendentLinkedList(struct node *head, int element)
{
    struct node *newNode, *previousNode, *actualNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;
    if(head == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        if(element <= head->key)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            actualNode = head->next;
            previousNode = head;
            while((actualNode != NULL) && (actualNode->key < element))
            {
                previousNode = actualNode;
                actualNode = actualNode->next;
            }
            newNode->next = actualNode;
            previousNode->next = newNode;
        }
    }
}

void printList(struct node *head)
{
    struct node *actualNode = head;
    while (actualNode != NULL)
    {
        printf("%d ", actualNode->key);
        actualNode = actualNode->next;
    }
    printf("NULL\n");
}

struct node *deleteElementOfAscendentLinkedList(struct node *head, int element)
{
    struct node *actualNode, *previousNode;
    if(head == NULL)
        printf("The Ascendent Linked list is empty.\n");
    else
    {
        if(element == head->key)
        {
            actualNode = head;
            head = head->next;
            free(actualNode);
        }
        else
        {
            actualNode = head->next;
            previousNode = head;
            while(actualNode != NULL && actualNode->key < element)
            {
                previousNode = actualNode;
                actualNode = actualNode->next;
            }
            if(actualNode == NULL)
                printf("The %d element is not in the A.L.L.\n", element);
            else
            {
               
            }
        }
    }
}