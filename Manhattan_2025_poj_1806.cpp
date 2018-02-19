#include<stdio.h>
int mod(int x)
{   if(x<0) return -x;
return x;
}
int main()
{   int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++)
    {   int u;
        scanf("%d",&u);
        printf("Scenario #%d:\n",z);
        int i, j, k;
        for(k=1; k<=(2*u + 1); k++)
        {   printf("slice #%d:\n",k);
            for(i=0; i<(2*u + 1); i++)
            {   for(j=0; j<(2*u + 1); j++)
                {   int a= mod(i-u) + mod(j-u) + mod(k-u-1);
                    if(a<=u)
                    printf("%d",a);
                    //arr[i][j]=((char)(a+'0'));
                    else
                    //arr[i][j]='.';
                    printf(".");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}
