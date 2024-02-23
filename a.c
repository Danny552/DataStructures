#include <stdio.h>
#include <math.h>
#define MAXT 100
int BinarySearch(int A[], int i, int j, int k)
{
    int result = -1, m;

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
                i = m - 1;
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
    int index, A[MAXT + 1], pages, forgottenPage;
    int totalCases, idCase, s;

    A[0] = 0;
    for (index = 1; index <= MAXT; index++)
        A[index] = A[index - 1] + index;

    scanf("%d", &totalCases);
    for (idCase = 1; idCase <= totalCases; idCase++)
    {
        scanf("%d", &s);
        index = BinarySearch(A, 1, MAXT, s);
        if (index >= 0)
        {
            pages = index + 1;
            forgottenPage = index + 1;
        }
        else
        {
            pages = -1 * index - 1;
            forgottenPage = A[pages] - s;
        }
        printf("%d %d\n", forgottenPage, pages);
    }
}
