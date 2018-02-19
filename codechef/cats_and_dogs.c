#include<stdio.h>
long long int min(long long int a, long long int b)
{   return a*(a<=b) + b*(b<a);
}
int main()
{   int t;
    scanf("%d",&t);
    long long int c, d, l;
    while(t--)
    {
    scanf("%lld%lld%lld",&c,&d,&l);
    if ((l<=(4*(c+d))) && (l>=(4*(c+d-min(2*d,c))) && (l%4==0)))
        printf("yes");
    else
        printf("no");
    if(t!=0)
        printf("\n");
    }
    return 0;
}
