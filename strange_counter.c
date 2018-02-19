#include<stdio.h>
int main()
{   long long int t, ans=3;
    scanf("%lld",&t);
    while(t>ans)
    {   t-=ans;
        ans*=2;
    }
    printf("%lld\n",ans-(t-1));
    return 0;
}
