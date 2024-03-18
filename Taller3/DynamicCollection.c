#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myInfinite 2147483647

//MergeSort

void MyMerge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1 + 2], R[n2 + 2];

    for(i=1 ; i<=n1 ; i++)
    {
        L[i] = A[p + i - 1];
    }

    for(j=1 ; j<=n2 ; j++)
    {
        R[j] = A[q + j];
    }

    L[n1 + 1] = myInfinite;
    R[n2 + 1] = myInfinite;
    i = 1;
    j = 1;

    for(k=p ; k<=r ; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int p, int r) //Siendo p el indice donde se empieza a ordenar y r donde termina de ordenarse
{
    int q;
    if(p < r)
    {
        q = (p + r) >> 1; // (p + r) >> 1;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        MyMerge(A, p, q, r);
    }
}

//MergeSort

//BinarySearch

int BinarySearch(int A[], int i, int j, int k) //k es el numero buscado, i es el primer elemento del arreglo, j es el ultimo elemento del arreglo
{
    int result = -1, m;
    while(i <= j)
    {
        m = (i+j) >> 1; /* m = (i+j) / 2; */
        if(k==A[m])
        {
            result = m;
            break;
        }
        else
        {
            if(k > A[m])
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }
    }
    if(result == -1)
    {
        result = -1 * i - 1;
    }

    return result;
}

//BinarySearch

//BinarySearchFirst

int BinarySearchFirstO(int A[], int i, int j, int k)
{
    int result, result2;
    result = BinarySearch(A, i, j, k);
    if(result >= 0)
    {
        result2 = BinarySearch(A,i,result - 1, k);
        while(result >= 0)
        {
            result = result2;
            result2 = BinarySearch(A, i, result - 1, k);
        }
    }

    return result;
}

//BinarySearchFirst

//BinarySearchLast

int BinarySearchLastO(int A[], int i, int j, int k)
{
    int result, result2;
    result = BinarySearch(A, i, j, k);
    if(result >= 0)
    {
        result2 = BinarySearch(A, result + 1 , j, k);
        while(result >= 0)
        {
            result = result2;
            result2 = BinarySearch(A, result + 1 , j, k);
        }
    }

    return result;
}

//BinarySearchLast

int main()
{
    int n, q, k, a, b, i, op, result, Ia, Ib;
    int C[2000002];
    scanf("%d %d", &n, &q);

    for(i=1;i<=n;i++)
    {
        scanf("%d", &C[i]);
    }

    MergeSort(C, 1, n);

    for(i=1;i<=q;i++)
    {
        scanf("%d ", &op);
        if(op == 1)
        {
            scanf("%d", &k);
            result = BinarySearch(C, 1, n, k);
            if(result < 0)
            {
                result = -1 * result - 1;
                if(result > n)
                {
                    C[result] = k;
                    n++;
                }
                else
                {
                    C[result] = k;
                }
            }
        }
        else
        {
            scanf("%d %d", &a, &b);
            Ia = BinarySearchFirstO(C, 1, n, a);
            Ib = BinarySearchLastO(C, 1, n, b);
            if(Ia < 0)
            {
                Ia = -1 * Ia - 1;
            }
            if(Ib < 0)
            {
                Ia = -1 * Ia - 1;
            }
            result = -1 * (Ib - Ia);
            printf("%d\n", result);
        }
    }

    return 0;
}