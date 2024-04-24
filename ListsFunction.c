#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int key;
    struct node *next;
};

struct node *make(int n){
    struct node *head,  *newnode;
    head = NULL;
    while (n >= 1){
        newnode = malloc(sizeof(struct node)); //"newnode apuntará a una direccion de memoria de tipo y tamaño nodo"
        newnode -> key = n;
        newnode -> next = head;
        head =  newnode;
        n --;
    }
    return head;
}

void showList (struct node *head){
    struct node *actualnode;
    actualnode = head;
    while (actualnode != NULL)
    {
        printf("%d -> ", actualnode -> key);
        actualnode = actualnode -> next;
    }
        printf("NULL");
}

struct node *delete(struct node *head){
    struct node *newnode;
    while (head != NULL){
        newnode = head -> next; 
        free(head);
        head = newnode;
    }  
}


int main(){
    struct node *head;
    int n;
    printf("Ingrese un numero\n");
    scanf("%d", &n);
    
    head = make(n);
    mostrar(head);
    free(head);
    return 0;
}