#include <stdio.h>
#include <math.h>

long long int GaussianVerification(long long int x,long long  int y)
{
    long long int Gauss = 1;
    if(x==1)
    {
        if(y%2 == 0) 
        {
            y--;
            Gauss = y*(y+1)/2 + 1; //Gauss(y-1) + 1
        }
        else
        {
            Gauss = y*(y+1)/2; //Gauss(y)
        }
    }
    else
    {
        if(y==1)
        {   
            if(x%2 == 0)
            {
                Gauss = x*(x+1)/2; //Gauss(x)
            }
            else
            {
                x--;
                Gauss = x*(x+1)/2 + 1; //Gauss(x-1) + 1
            }
        }
    }
    return Gauss;
}

long long int UpOrDown(long long int x,long long int y)
{
    long long int result, index = 0;
    if((x+y)%2 == 0) //Subiendo
    {
        while(y != 1)
        {
            index++;
            y--;
            x++;
        }
        result = GaussianVerification(x, y) + index;
    }
    else //Bajando
    {
        while(x != 1)
        {
            index++;
            y++;
            x--;
        }
        result = GaussianVerification(x, y) + index;
    }
    return result;
}

int main()
{
    long long int x, y, result;
    while(scanf("%lld %lld", &x, &y) && y!=0 && x != 0)
    {
        if(x==1 || y==1)
        {
            result = GaussianVerification(x, y);
        }
        else
        {
            result = UpOrDown(x, y);
        }
        printf("%lld\n", result);
    }

    return 0;
}