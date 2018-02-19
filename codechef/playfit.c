#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n, min=1000001, dmax=0, x;
        scanf("%d",&n);
        while(n--)
        {   scanf("%d",&x);
            if(x<min) min=x;
            else if(x>min) {if(dmax<x-min) dmax=x-min;}
            //printf("%d %d\n",min, dmax);
        }
        if(dmax) printf("%d\n",dmax);
        else printf("UNFIT\n");
    }
    return 0;
}
