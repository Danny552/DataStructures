#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXT 1000000
#define MYINFINITE 2147483647

int Left(int i) 
{
    return 2 * i;
}

int Right(int i) 
{
    return 2 * i + 1;
}

int Parent(int i) 
{
    return i / 2;
}

void MinHeapify(int Q[], int i, int heapSize) 
{
    int l, r, least, temp;
    l = Left(i);
    r = Right(i);
    if ((l <= heapSize) && Q[l] < Q[i]) 
    {
        least = l;
    } 
    else 
    {
        least = i;
    }
    if ((r <= heapSize) && Q[r] < Q[least]) 
    {
        least = r;
    }
    if (least != i) 
    {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, (heapSize));
    }
}

int MinPQ_Minimum(int Q[]) 
{
    return Q[1];
}

int MinPQ_Extract(int Q[], int *heapSize) 
{
    int min = MYINFINITE;
    if (*heapSize < 1) 
    {
        printf("Heap underflow\n");
    } 
    else 
    {
        min = Q[1];
        Q[1] = Q[*heapSize];
        (*heapSize)--;
        MinHeapify(Q, 1, (*heapSize));
    }
    return min;
}

void MinPQ_DecreaseKey(int Q[], int i, int key) 
{
    int temp;
    if (key > Q[i]) 
    {
        printf("New key is higher than current key\n");
    } 
    else 
    {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)] > Q[i])) 
        {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert(int Q[], int key, int *heapSize) 
{
    (*heapSize)++;
    Q[*heapSize] = MYINFINITE;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main()
{
    int QA[MAXT + 1], QB[MAXT + 1], m, n, heapsizeA, heapsizeB, i, element, elementA, elementB, intersect;
    
    while(scanf("%d %d", &m, &n) && (m > 0) && (n > 0)) 
    {
        heapsizeA = 0;
        heapsizeB = 0;
        intersect = 0;

        for (i = 1; i <= m; i++) 
        {
            scanf("%d", &element);
            MinPQ_Insert(QA, element, &heapsizeA);
        }
        for (i = 1; i <= n; i++) 
        {
            scanf("%d", &element);
            MinPQ_Insert(QB, element, &heapsizeB);
        }

        while((heapsizeA >= 1) && (heapsizeB >= 1))
        {
            elementA = MinPQ_Minimum(QA);
            elementB = MinPQ_Minimum(QB);

            if(elementA == elementB)
            {
                intersect++;
                MinPQ_Extract(QA, &heapsizeA);
                MinPQ_Extract(QB, &heapsizeB);
            }
            else if(elementA < elementB)
            {
                MinPQ_Extract(QA, &heapsizeA);
            }
            else
            {
                MinPQ_Extract(QB, &heapsizeB);
            
            }
        }

        printf("%d %d %d %d\n", m - intersect, intersect, n - intersect, m + n - intersect);
    }
    return 0;
}