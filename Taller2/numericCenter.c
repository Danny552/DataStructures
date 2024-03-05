#include <stdio.h>
#include <math.h>

int BinarySearch(int A[], int i, int j, int k) {
    int result = -1, h;

    while (i <= j) {
        h = (i + j) / 2;
        if (k == A[h]) {
            result = h;
            break;
        } else {
            if (k > A[h])
                i = h + 1;
            else
                j = h - 1;
        }
    }
    if (result == -1)
        result = -1 * i - 1;

    return result;
}

int main() {

    int lista[8];

    int contador = 0;
    for (unsigned long long int i = 1; i < 1000000; i++) {

        unsigned long long int gauss = (i * (i + 1)) / 2;
        double centro = sqrt(gauss);

        if (floor(centro) == ceil(centro)) {

            lista[contador] = centro;
            contador++;

        }
    }

    unsigned long long int n;
    while (1) {

        scanf("%lld", &n);

        if (n == 0) {
            break;
        }

        unsigned long long int sumatoria = sqrt((n * (n + 1)) / 2);

        int busqueda = BinarySearch(lista, 0, 7, sumatoria);

        if (busqueda < 0) {

            printf("%d\n", (-1 * busqueda) - 2);

        } else {

            printf("%d\n", busqueda);
        }
    }

    return 0;
}
