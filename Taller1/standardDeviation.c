#include <stdio.h>
#include <math.h>

int main() {
    long int n;
    double standardDeviation;

    while(scanf("%d", &n) && (n!=0)){
     standardDeviation = (sqrt(n*(n + 1)) / sqrt(3));
        printf("%f\n", standardDeviation);
    }

    return 0;
}