#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int key;
    struct node *next;
};

struct node *insertElementInAscendantLinkedList(struct node *head, int element)
{
    struct node *newNode, *previousNode, *actualNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> key = element;
    if(head == NULL)
    {
        newNode -> next = head;
        head = newNode;
    }
    else
    {
        if(element <= head -> key)
        {
            newNode -> next = head;
            head = newNode;
        }
        else
        {
            actualNode = head -> next;
            previousNode = head;
            while ((actualNode != NULL) && (actualNode -> key < element))
            {
                previousNode = actualNode;
                actualNode = actualNode -> next;
            }
            newNode -> next = actualNode;
            previousNode -> next = newNode;
        }        
    }
    return head;
}

struct node *deleteElementOfAscendentLinkedList(struct node *head, int element)
{
    struct node *actualNode, *previousNode;
    if(head == NULL)
    {
        printf("The ascendent Linked List is empty.\n");
    }
    else
    {
        if(element < head -> key)
        {
            printf("The %d is not in the ascendent Linked List.\n", element);
        }
        else
        {
            if(element == head -> key)
            {
                actualNode = head;
                head = head->next;
                free(actualNode);
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
                if(actualNode == NULL)
                {
                    printf("The %d is not in the Ascendent Linked List.\n", element);
                }
                else
                {
                    if(actualNode->key != element)
                    {
                        printf("The %d is not in the Ascendent Linked List.\n", element);
                    }
                    else
                    {
                        previousNode->next = actualNode->next;
                        free(actualNode);
                    }
                }
            }
        }-
    }
    return head;
}

void printList(struct node *head)
{
    struct node *actualNode = head;
    while(actualNode != NULL)
    {
        printf("%d -> ", actualNode->key);
        actualNode = actualNode->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    int n, element, idElement;
    long long int result;

    while(scanf("%d", &n) && (n>0))
    {
        for(idElement = 1; idElement <= n; idElement++)
        {
            scanf("%d", &element);
            head = insertElementInAscendantLinkedList(head, element);
        }

        result = 0;
        for(idElement = 1; idElement < n; idElement++)
        {
            element = head->key;
            head = deleteElementOfAscendentLinkedList(head, element);
            element += head->key;
            head = deleteElementOfAscendentLinkedList(head, head->key);
            result += element;
            head = insertElementInAscendantLinkedList(head, element);
        }

        printf("%lld\n", result);
        free(head);
        head = NULL;
    }

    return 0;
}