#include<stdio.h>
int max(int a, int b)
{   if(a>=b) return a;
    return b;
}
int up(float x)
{   if(x<0)         return 0;
    if(x== (int)x)  return (int)x;
    else            return 1+(int)x;
}
int main()
{   int test;
    scanf("%d",&test);
    while(test--)
    {   int n;
        scanf("%d",&n);
        int x[n],l[n],f[n];
        for(int i=0; i<n; i++)
            scanf("%d %d %d",&x[i],&l[i],&f[i]);
        int t=x[0];
        for(int i=0; i<n-1; i++)
        {   t+=l[i];
            int a=x[i+1]+(f[i+1]*up((float)(t-x[i+1])/f[i+1]));
            if(t<a) t=a;
            //printf("%d",t);
        }
        t+=l[n-1];
        printf("%d\n",t);
    }
    return 0;
}
