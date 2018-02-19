#include<math.h>
#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n;
        scanf("%d",&n);
        int inp[n][2];
        float d=0;
        for(int i=0; i<n; i++)
        {   scanf("%d %d",&inp[i][0],&inp[i][1]);
        }
        for(int i=0; i<n-1; i++)
        {   d+=sqrt(((inp[i+1][0]-inp[i][0])*(inp[i+1][0]-inp[i][0]))+((inp[i+1][1]-inp[i][1])*(inp[i+1][1]-inp[i][1])));
        }
        printf("%.2f\n",d);
    }
return 0;
}
