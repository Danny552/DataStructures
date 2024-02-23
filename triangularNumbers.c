#include <stdio.h>
#include <math.h>

int main (){
    unsigned long long int num, serie, pos,posMas1;
    while (1){
    scanf ("%lld", &num);
    if (num == 0){
        break;
    }
    pos = floor((unsigned long long int)(sqrt(1 + 8 * (double)num) - 1) / 2);
    posMas1 = pos + 1;
    if(pos % 2 == 0){    
    pos = pos / 2;
    } else {  
    posMas1 = posMas1 / 2;
    }
    serie = pos * posMas1;
    if (num == serie){
        printf ("YES\n");
    } else {
        printf ("NO\n");
        }
    }
}