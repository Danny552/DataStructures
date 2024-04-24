
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *insertElementInCircularLinkedList(struct node *tail, int element)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;
    if (tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

struct node *deleteFirstNodeInCircularLinkedList(struct node *tail)
{
    struct node *firstNode;
    if (tail == NULL)
        printf("The circular linked list is empty.\n");
    else
    {
        if (tail == tail->next)
        {
            free(tail);
            tail = NULL;
        }
        else
        {
            firstNode = tail->next;
            tail->next = firstNode->next;
            free(firstNode);
        }
    }
    return tail;
}

void printCircularLinkedList(struct node *tail)
{
    struct node *actualNode;
    if (tail == NULL)
        printf("NULL\n");
    else
    {
        actualNode = tail->next;
        while (actualNode != tail)
        {
            printf("%d -> ", actualNode->key);
            actualNode = actualNode->next;
        }
        printf("%d ...\n", tail->key);
    }
}

int josephus(int n, int k)
{
    struct node *tail = NULL;
    int i;

    for (i = 1; i <= n; i++) //llena la lista 
    {
        tail = insertElementInCircularLinkedList(tail, i);
    }

    while (tail != tail->next) //mientras la lista tenga mas de un elemento 
    {
        for (i = 1; i < k; i++)
        {
            tail = tail->next;
        }
        tail = deleteFirstNodeInCircularLinkedList(tail);
    }
    int survivor = tail->key;
    free(tail); 
    return survivor;
}

int main()
{
    int n, k;
    while (scanf( "%d %d", &n, &k) && n != 0 && k != 0){
    int survivor = josephus(n, k);
    printf("%d\n", survivor);
    }
    return 0;
}