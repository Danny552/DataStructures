#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int key;
    int money;
    struct node *next;
    struct node *prev;
};

struct operations
{
    char M;
    int R;
    int A;
};

struct node *insertElementInAscendentLinkedList(struct node *head, int element, int money)
{
    struct node *newNode, *previousNode, *actualNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;
    newNode->money = money;
    if (head == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        if (element <= head->key)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            actualNode = head->next;
            previousNode = head;
            while ((actualNode != NULL) && (actualNode->key < element))
            {
                previousNode = actualNode;
                actualNode = actualNode->next;
            }
            newNode->next = actualNode;
            previousNode->next = newNode;
        }
    }
    return head;
}

void printList(struct node *head)
{

    struct node *actualNode = head;
    while (actualNode != NULL)
    {
        printf("%d %d\n", actualNode->key, actualNode->money);
        actualNode = actualNode->next;
    }
}

void printFromLists(struct node *tail)
{
    struct node *actualNode;
    if (tail == NULL)
        printf("NULL.\n");
    else
    {
        actualNode = tail->next;
        while (actualNode != tail)
        {
            printf("%d -> ", actualNode->key);
            actualNode = actualNode->next;
        }
        printf("%d -> ...\n", actualNode->key);
    }
}

struct node *insertElementInCircularDoublyLinkedList(struct node *tail, int element, int cash)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;
    newNode->money = cash;
    if (tail == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        newNode->next->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}

struct node *deleteElementOfCircularDoublyLinkedList(struct node *tail, int element)
{
    struct node *actualNode;
    if (tail == NULL)
        printf("The list is empty.\n");
    else
    {
        if (tail == tail->next)
        {
            if (tail->key == element)
            {
                free(tail);
                tail = NULL;
            }
            else
                printf("the %d element is not in the list", element);
        }
        else
        {
            if (tail->key == element)
            {
                actualNode = tail;
                tail = tail->prev;
                actualNode->next->prev = actualNode->prev;
                actualNode->prev->next = actualNode->next;
                free(actualNode);
            }
            else
            {
                actualNode = tail->next;
                while ((actualNode->key != element) && (actualNode != tail))
                {
                    actualNode = actualNode->next;
                }

                if (actualNode == tail)
                    printf("The %d is not in the list.\n", element);
                else
                {
                    actualNode->next->prev = actualNode->prev;
                    actualNode->prev->next = actualNode->next;
                    free(actualNode);
                }
            }
        }
    }
    return tail;
}

int main()  //Liberar las listas despues de cada ronda
{
    struct node *tail = NULL, *head = NULL, *actualPlayerNode = NULL, *eraseNode = NULL;
    int N, D, R, A, i = 0, j = 0;
    char M;

    while (scanf("%d", &N) != EOF)
    {
        i = 0;// Inicializacion

        // printf("Valor N %d\n", N); // Prueba
        tail = NULL;
        head = NULL;

        scanf("%d", &D);
        
        for (i = 1; i <= N; i++)
        {
            tail = insertElementInCircularDoublyLinkedList(tail, i, D);
        }
        actualPlayerNode = tail->next;

        struct operations op[N];

        for(j = 0; j < (N-1); j++) //Lectura de los lanzamientos
        {
            scanf("\n%c %d %d", &M, &R, &A);
            op[j].M = M;
            op[j].R = R;
            op[j].A = A;
        }
        i = 0;
        while (1) // Ejecucion ronda
        {
            if (tail == tail->next)
            {
                eraseNode = actualPlayerNode;
                head = insertElementInAscendentLinkedList(head, tail->key, tail->money);
                // printf("ultimo %d\n", tail->key); // Prueba
                tail = deleteElementOfCircularDoublyLinkedList(tail, eraseNode->key);

                printList(head);
                // printf("Break\n"); // Prueba

                break;
            }

            M = op[i].M;
            R = op[i].R;
            A = op[i].A;

            // printf("Actual %d\n", actualPlayerNode->key); // Prueba
            

            if (M == 'C')
            {
                for (int j = 0; j < R; j++)
                {
                    actualPlayerNode = actualPlayerNode->next;
                }
            }
            else
            {
                for (int j = 0; j < R; j++)
                {
                    actualPlayerNode = actualPlayerNode->prev;
                }
            }
            // printf("Actual %d\n", actualPlayerNode->key); // Prueba
            actualPlayerNode->money += A;

            if (((actualPlayerNode->money) % 2) == 0) // Eliminar adyacentes
            {
                // printf("Elimino %d\n", actualPlayerNode->next->key); // Prueba
                tail = deleteElementOfCircularDoublyLinkedList(tail, actualPlayerNode->next->key);
                // printFromLists(tail); // Prueba
                if (actualPlayerNode->prev != actualPlayerNode)
                {
                    // printf("Elimino %d\n", actualPlayerNode->prev->key); // Prueba
                    tail = deleteElementOfCircularDoublyLinkedList(tail, actualPlayerNode->prev->key);
                    // printFromLists(tail); // Prueba
                }
            }
            else // Se salva a si mismo
            {

                if (actualPlayerNode != actualPlayerNode->next)
                {

                    head = insertElementInAscendentLinkedList(head, actualPlayerNode->key, actualPlayerNode->money);
                    // printf("Salvado %d con %d\n", actualPlayerNode->key, actualPlayerNode->money); // Prueba
                    eraseNode = actualPlayerNode;
                    if (M == 'C')
                    {
                        actualPlayerNode = actualPlayerNode->next;
                    }
                    else
                    {
                        actualPlayerNode = actualPlayerNode->prev;
                    }
                    tail = deleteElementOfCircularDoublyLinkedList(tail, eraseNode->key);
                    // printf("Actual %d\n", actualPlayerNode->key); // Prueba
                    // printFromLists(tail); // Prueba
                }
            }
            i++;
        }   // Ejecucion ronda
    }

    return 0;
}