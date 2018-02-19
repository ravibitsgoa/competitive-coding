#include<stdio.h>
long long ex(long long a, long long k)
{   if(k==0)    return 1;
    if(k==1)    return a;
    if(k%2)     {long long x=ex(a, (k-1)/2);    return a*x*x;}
    else        {long long y=ex(a, k/2);        return y*y;}
}
int main()
{
    printf("%lld", ex(10, 18));
    return 0;
}
