#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n, c=0;
        scanf("%d",&n);
        char x[10005];
        scanf("%s",x);
        for(int i=0; i<n; i++)
        {   if(x[i]=='1') c++;
        }
        printf("%d\n",c*(c+1)/2);
    }
    return 0;
}
