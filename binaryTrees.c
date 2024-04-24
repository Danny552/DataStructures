#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void inOrderTreeWalk(int x){
    if (x != NULL)
    {
        inOrderTreeWalk(left[x])    
    }
    
}