#include<stdio.h>
int main()
{   int t, n, x, y, c;
    scanf("%d",&t);
    while(t--)
    {   scanf("%d",&n); c=0; y=0;
        while(n--)
        {   scanf("%d",&x);
            if(y>=x || y==0)
            {   c++;
            }
            else{x=y;}
            y=x;
        }
        printf("%d\n",c);
    }
    return 0;
}
