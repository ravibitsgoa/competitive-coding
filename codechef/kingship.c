#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   long long int n, sum=0, min, x;
        scanf("%lld%lld",&n,&min);
        n--;
        sum+=min;
        while(n--)
        {   scanf("%lld",&x);
            if(x<min) min=x;
            sum+=x;
        }
        sum-=min;
        printf("%lld\n",sum*min);
    }
    return 0;
}
