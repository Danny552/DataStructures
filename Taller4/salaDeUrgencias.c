#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myNegativeInfinite -9223372036854775807
#define myPositiveInfinite 9223372036854775807
#define MAXT 200000

 struct person{
    long long int priority;
    char name [22];
    long long int seconds;
    
};

int Parent(int i){
    return i / 2;
}

int Left(int i){
    return 2 * i;
}

int Right(int i){
    return 2 * i + 1;
}

void MinHeapify(struct person Q[], int i, int heapSize){
    int l, r, least;
    
    struct person temp;
    
    l = Left(i);
    r = Right(i);
    
    if((l <= heapSize) && (Q[l].priority < Q[i].priority)) least = l;
    else least = i;
    
    if((r <= heapSize) && (Q[r].priority < Q[least].priority)) least = r;
    
    if(least != i){
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
    }
}

 struct person  MinPQ_Minimum(struct person Q[]){
    return Q[1];
}

struct person MinPQ_Extract(struct person Q[], int *heapSize){
    struct person myMin;
    myMin.priority = myNegativeInfinite;
    
    if(*heapSize < 1) printf("heap underflow.\n");
    else{
        myMin = Q[1] ;
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        MinHeapify(Q, 1, *heapSize);
    }
    
    return myMin;
}

void MinPQ_DecreaseKey(struct person Q[], int i, struct person key){
    struct person temp;
    
    if(key.priority > Q[i].priority) printf("new key is higher than current key.");
    else{
        Q[i] = key;
        while((i > 1) && (Q[Parent(i)].priority > Q[i].priority)){
            temp = Q[Parent(i)];
            Q[Parent(i)] = Q[i];
            Q[i] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert(struct person Q[], struct person key, int *heapSize){
    *heapSize = *heapSize + 1;
    Q[*heapSize].priority = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main(){
    
    int t, heapSize = 0, n;
    long long int p, key, h;
    char name[22];
    
    struct person Q[MAXT + 2], user;
    
    while (scanf("%d", &n) != EOF){
        
        heapSize = 0;
        
        while (n != 0){
        
            scanf("%d", &t);
            scanf("%lld", &h);
            if(t == 1){
                
                
                
                scanf("%lld", &p);
                scanf("%s", name);
                
                
                key = (p * 1000000) + h;
                
                //printf("%lld\n",priority);
                
                strcpy(user.name, name);
                user.seconds = h;
                user.priority = key;
                MinPQ_Insert(Q, user, &heapSize);
                
            }else{
                
                
                if (heapSize <= 0){
                    printf("\n");
                }else{
                    user = MinPQ_Extract(Q, &heapSize);
                    printf("%lld %lld %lld %s\n", user.seconds, h, (h - user.seconds), user.name );
                    
                }
                
            }
            
            n --;
        }
        
    }
   
     return 0;  
}