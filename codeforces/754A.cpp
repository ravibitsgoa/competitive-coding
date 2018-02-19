#include<stdio.h>
int main()
{   int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int flag=0;
    for(int i=0; i<n; i++)
    {   if(a[i]!=0)
            flag=1;
    }
    if(!flag)
        printf("NO\n");
    else
    {   printf("YES\n");
        int sum=0, x=1, i;
        for(i=0; i<n; i++)
        {   sum+=a[i];
            if(sum==0 && i!=x-1)
            {   printf("%d %d\n",x,i);
                x=i+1;
                sum=a[i];
            }
        }
        printf("%d %d\n",x,i);
    }
return 0;
}
