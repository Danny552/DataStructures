#include <stdio.h>
#include <math.h>

int main() {
    int n, HM;

    while(scanf("%d", &n) && (n!=0)){
        HM = ceil(sqrt(n));
        printf("%d\n", HM);
    }

    return 0;
}