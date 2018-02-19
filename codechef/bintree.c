#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int i, j;
        scanf("%d %d",&i, &j);
        int step=0;
        while(i!=j)
        {   if(i>j) i/=2;
            else j/=2;
            step++;
        }
        printf("%d\n",step);
    }
    return 0;
}
