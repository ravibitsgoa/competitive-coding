#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n, a, b;
        scanf("%d %d %d",&n,&a,&b);
        if(b<a)
        {   int temp=b; b=a; a=temp;
        }//making 'a' the smaller one.
        int ans=(n-1)*a;
        if(a!=b)
        {   for(int i=0; i<n; i++)
            {   printf("%d ",ans);
                ans+=b-a;
            }
        }
        else
            printf("%d",ans);
        printf("\n");
    }
return 0;

}
