#include <stdio.h>
#define MAX 500000
#define myInfinite 2147483647

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

void MergeSort(int A[], int p, int r)
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

int binarySearch(int A[],int i,int j,int k ){
    int r= -1, m;
    while (i <= j)
    {   // OPERACIONES CON BITS CONSULTAR, dividir o potenciar por potendias de 2
        m = (i + j) >> 1;
        if (k == A[m])
        {
            r = m; 
            break;
        }else if (k > A[m])
        {
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }
    if (r == -1)
    {
        return (-1 * i) - 1;
    }else
    {
        return r;
    }      
}

int main(){
    int n, q, A[MAX +1], idElement, idQuery, s, i, elemennt, index;
    long long int result;
    scanf("%d %d", &n, &q);

    for (idElement = 1; idElement <= n; idElement++)
        scanf("%d", &A[idElement]);

    MergeSort(A, 1, n);

    for (idQuery = 1; idQuery <= q; idQuery++){
        result = 0;
        scanf("%d", &s);
        for (i = 1; i < n; i++)
        {
            elemennt = s - A[i];
            if (elemennt > i)
            {
                index = binarySearch(A, i+ 1 , n, elemennt);
                if (index < 0)
                    index = -1 * index - 2;

                result += (index - i);
            }
            
        }  
        printf("%llu\n", result);
        }
}