#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n;
        scanf("%d",&n);
        char x[n];
        scanf("%s",x);
        if(x[0]=='1' && x[1]=='0') {x[1]='2';}
        if(x[n-1]=='1' && x[n-2]=='0') {x[n-2]='2';}
        for(int i=1; i<n-1; i++)
        {   if(x[i]=='1')
            {   if(x[i-1]=='0') {x[i-1]='2';}
                if(x[i+1]=='0') {x[i+1]='2';}
            }
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {   if(x[i]=='0'){ans++;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
