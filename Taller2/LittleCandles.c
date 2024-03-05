#include <stdio.h>
#include <math.h>
#define MAX 1836092

long long int BinarySearch(long long int A[], long long int i, long long int j, long long int k)
{
    long long int result = -1, m;

    while (i <= j)
    {
        m = (i + j) >> 1;
        if (k == A[m])
        {
            result = m;
            break;
        }
        else
        {
            if (k > A[m])
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }
    }
    if (result == -1)
    {
        result = -1 * i - 1;
    }
    return result;
}

int main()
{
    long long int sumaTriangulares[MAX + 1], numeroTriangulos, n, numeroTriangulosTOT = 0, comp;

    for (long long int i = 2; i <= MAX; i++)
    {
        sumaTriangulares[i - 1] = ((i + 2) * (i + 1) * i / 6) - 1;
    }

    while (scanf("%lld", &n) != EOF)
    {
        numeroTriangulosTOT = 0;

        while (n > 2)
        {
            comp = BinarySearch(sumaTriangulares, 1, MAX, n);
            if(comp > 0){
                numeroTriangulos = comp;
            } else {
                numeroTriangulos = -1 * comp -2;
            }
            numeroTriangulosTOT += numeroTriangulos;
            n -= sumaTriangulares[numeroTriangulos];
        }
        printf("%lld %lld\n", numeroTriangulosTOT, n);
    }

    return 0;
}