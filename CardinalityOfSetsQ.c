#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myInfinite 2147483647
#define MAXT 200000

int Parent(int i)
{
    return i/2;
}

int Left(int i)
{
    return 2 * i;
}

int Right(int i)
{
    return 2 * i + 1;
}

void MinHeapify(int Q[], int i, int heapSize)
{
    int l, r, least, temp;
    l = Left(i);
    r = Right(i);

    if((l <= heapSize) && (Q[l] < Q[i]))
    {
        least = l;
    }
    else
    {
        least = i;
    }

    if((r <= heapSize) && (Q[r] < Q[least]))
    {
        least = r;
    }

    if(least != i)
    {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
    }
}

int MinPQ_Minimum(int Q[])
{
    return Q[1];
}

int MinPQ_Extract(int Q[], int *heapSize)
{
    int myMin = myInfinite;
    if(*heapSize < 1)
    {
        printf("Heap underflow.\n");
    }
    else
    {
        myMin = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        MinHeapify(Q, 1, *heapSize);
    }

    return myMin;
}

void MinPQ_DecreaseKey(int Q[],int i,int key)
{
    if(key > Q[i])
    {
        printf("New key is higher than current key.\n");
    }
    else
    {
        Q[i] = key;
        while( (i > 1) && (Q[Parent(i)] > Q[i]))
        {
            int temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert(int Q[], int key, int *heapSize)
{
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main()
{
    int Q[MAXT + 1], m, n, heapsize, i, element, intersect;
    
    while(scanf ("%d %d", &m, &n) && (m > 0) && (n >> 0)){
        heapsize = 0;
        intersect = 0;

        for (i = 1; i <= m; i++){
            scanf ("%d", &element);
            MinPQ_Insert(Q, element, &heapsize);
        }
        for (i = 1; i <= n; i++){
            scanf ("%d", &element);
            MinPQ_Insert(Q, element, &heapsize);
        }
        while (heapsize >= 2)
        {
            element = MinPQ_Extract(Q, &heapsize);
            if(element == MinPQ_Minimum(Q))
            intersect++;
        }
        printf ("%d %d %d %d", m - intersect, intersect, n- intersect, m + n - intersect);
    }

    
    return 0;
}