#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n;
        scanf("%d",&n);
        char x[n];
        scanf("%s",x);
        int a=0;
        for(int i=0; i<n; i++)
        {   if(x[i]=='1') {a++;}
        }
        printf("%d\n",(a+ (a*(a-1)/2)));
    }
    return 0;
}
