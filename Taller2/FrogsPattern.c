#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define myInfinite 2147483647
#define MAXO 1200000

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

int main()
{
    int n, q, j, i, h, temp;
    scanf("%d", &n); //Cantidad de ranas

    int X[n+1]; //Posiciones iniciales de las ranas

    for(i=1;i<=n;i++) //X[i] es la posicion inicial de la rana i
    {
        scanf("%d", &X[i]);
    }
    
    //Arreglo de nenufares libres
    int L[MAXO + 1];
    int c = 1, t = 1;
    for(i=1;i<=MAXO;i++)
    {
        if(X[c] == i)
        {
            c++;
        }
        else
        {
            L[t] = i;
            t++;
        }
    }

    scanf("%d", &q); //Numero de saltos totales

    for(i=1;i<=q;i++)
    {
        scanf("%d", &j); //Rana que salta
        h = -1 * BinarySearch(L, 1, MAXO - n, X[j]) - 1;
        temp = L[h];
        L[h] = X[j];
        X[j] = temp;

        printf("%d\n", X[j]);
    }

}