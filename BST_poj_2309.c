#include<stdio.h>
int lg(int x)
{   int ans=0, i=1;
    while(x%i==0)
    {ans++; i*=2;}
    return ans-1;
}
int main()
{   int n;
    scanf("%d",&n);
    while(n--)
    {   int x, level, min, max;
        scanf("%d",&x);
        level=lg(x);//this function calculates level of x in BST
        //v 1.0: min=max=x;
        /*while(level--)
        {   min-=1<<level;
            max+=1<<level;
        }*/
        //v 2.0:
        min=x-((1<<level) -1);
        max=2*x - min;
        printf("%d %d\n",min,max);
    }
    return 0;
}
