#include<iostream>
#include<cstdio>
int gcd(int a, int b)
{   if(a==0)    return b;
    if(b==0)    return a;
    if(a==1 || b==1) return 1;
    if(a>b)     return gcd(a%b, b);
    return gcd(a, b%a);
}
using namespace std;
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int g=a[0];
        for(int i=1; i<n; i++)
        {   g=gcd(g, a[i]);
            if(g==1) break;
        }
        if(g>1) printf("-1\n");
        else printf("%d\n",n);
    }
    return 0;
}
