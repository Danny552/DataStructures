#include <stdio.h>
#include <stdlib.h>

//Algoritmo de ordenamiento por mezclas.

void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int A[] = {1, 5, 5, 4, 2, 1, 5, 0, 912, 23, 5, 67, 875, 34, 23};
    int A_size = sizeof(A) / sizeof(A[0]);

    printf("Aay original: \n");
    for (int i = 0; i < A_size; i++)
        printf("%d ", A[i]);

    mergeSort(A, 0, A_size - 1);

    printf("\nAay ordenado: \n");
    for (int i = 0; i < A_size; i++)
        printf("%d ", A[i]);

    return 0;
}
