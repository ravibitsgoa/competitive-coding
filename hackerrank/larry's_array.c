#include<stdio.h>
int main()//hackerrank. medium, implementation of algo. (naive algo O(n^2), to count the number of inversions in the input array.
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int n;
        scanf("%d",&n);
        int inp[n];
        for(int i=0; i<n; i++)
            scanf("%d",&inp[i]);
        int noofinv=0;
        for(int i=0; i<n; i++)
        {   for(int j=i+1; j<n; j++)
            {   if(inp[j]<inp[i])
                    noofinv++;
            }
        }
        if(noofinv%2)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
