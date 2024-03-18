#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myinfinite 2147483647
#define MAXT 1000000


void mymerge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1; 
    int n2 = r - q;
    int i, j, k;
     
    int L[n1 + 2], R[n2 + 2]; //sumamos 2 por el index
    
    for(i = 1; i <= n1; i++)
         L[i] = A[p + i - 1];
         
    for(j = 1; j <= n2; j++)
         R[j] = A[q + j];
         
    L[n1 + 1] = myinfinite;
    R[n2 + 1] = myinfinite;
    i = 1;
    j = 1;
    
    for(k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;            
        }
    }
}

void mergesort(int A[], int p, int r)
{
    int q;
    
    if(p < r)
    {
        q = (p + r) >> 1; //(p + r) / 2
        mergesort (A, p, q);
        mergesort (A, q + 1, r);
        mymerge (A, p, q, r);
    } 
    
}

int binarysearch (int A[], int i,int j, int k)
//k es el numero buscado, i es el primer elemento del arreglo, j es el ultimo elemento del arreglo
{
  int result = -1, m;

  while (i <= j)
  {
     m = (i + j) >> 1; // m = (i+j)/2
     if (k == A[m])
     {
         result = m;
         break;
     }
     else
     {
        if (k > A[m])
        i = m + 1;
        else
        j = m - 1;
     }

  }

  if (result == -1)
{
      result = -1 * i - 1;
} 
     return result;

}



int main(){
    int x, n, l1, l2; //x abertura, n numero de fichas
    int piezas[MAXT + 1];
    int result;
    
  
        while(scanf("%d %d", &x, &n) != EOF)
    {
        x *= 10000000; //convertir el cm a nm
        result = 0; //falso
        for (int i = 1; i <= n; i++)
            scanf("%d", &piezas[i]);
    
        mergesort(piezas, 1, n);
        
    l1 = 1;
    l2 = n;
    
    while(l1 < l2){
        //llama la busqueda binaria con el vector piezas, partiendo de l1+1 
        //hasta n, buscando un valor =x-piezas[1]
        l2 = binarysearch(piezas, l1 + 1, n, x-piezas[l1]);
        
        //que l2 sea maypr que 0 implica que se encontro 
        if (l2 > 0){
            result = 1; //true
            printf("yes %d %d\n", piezas[l1], piezas[l2]);
            break;
        }
        else{
            l2 = -l2 - 1; //vuelve positivo l2 y disminuye su posicion
            l1++;
        }
    }
    
if (result == 0)
printf("danger\n");
    }
    return 0;
}