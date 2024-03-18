#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
// Algoritmo de ordenamiento por mezclas.

void merge(char *A[], long long int left, long long int mid, long long int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *L[n1], *R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        strcpy(L[i], A[left + i]);
    }

    for (j = 0; j < n2; j++) {
        R[j] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        strcpy(R[j], A[mid + 1 + j]);
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(A[k], L[i]);
            free(L[i]);
            i++;
        } else {
            strcpy(A[k], R[j]);
            free(R[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(A[k], L[i]);
        free(L[i]);
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(A[k], R[j]);
        free(R[j]);
        j++;
        k++;
    }
}

void mergeSort(char *A[], long long int left, long long int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int LexicographicBinarySearch(char *A[], long long int i, long long int j, const char target[]) {
    int result = -1, m;

    while (i <= j) {
        m = (i + j) / 2;

        int cmp = strcmp(target, A[m]);

        if (cmp == 0) {
            result = m;
            break;
        } else if (cmp > 0) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    if (result == -1) {
        result = -1 * i - 1;
    }

    return result;
}

int main() {
    long long int n, q, rangeIzq, rangeDer;
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
    scanf("%lld %lld", &n, &q);
    char *A[n];

    for (int i = 0; i < n; i++) {
        A[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        scanf("%s", A[i]);
    }

    mergeSort(A, 0, n - 1);

    for (int i = 1; i <= q; i++) {
        scanf("%s %s", str1, str2);
        rangeIzq = LexicographicBinarySearch(A, 0, n - 1, str1);
        if (rangeIzq < 0){
            rangeIzq = rangeIzq * -1;
        } else {
            rangeIzq = rangeIzq + 1;
        }
        rangeDer = LexicographicBinarySearch(A, 0, n - 1, str2);
            if (rangeDer < 0){
            rangeDer = rangeDer * -1;
        } else {
            rangeDer = rangeDer + 2;
        }
        printf("%lld\n", (rangeDer - rangeIzq));
    }
    return 0;
}