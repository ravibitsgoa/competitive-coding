#include<stdio.h>
int main()
{   int n;
    scanf("%d",&n);
    int max=0, l=0, x;
    while(n--)
    {   scanf("%d",&x);
        if(x!=0){l++;}
        else
        {   if(max<l){max=l;}
            l=0;
        }
    }
    printf("%d\n",max);
    return 0;
}
