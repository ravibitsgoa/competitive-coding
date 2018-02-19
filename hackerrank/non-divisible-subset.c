#include<stdio.h>
int max(int x, int y)
{   if(x>=y) return x;
else return y;
}
int main()
{   int n, k;
    scanf("%d %d",&n,&k);
    int freq[k], x;
    while(n--)
    {   scanf("%d",&x);
        if(freq[x%k]>n) freq[x%k]=0;
        freq[x%k]++;
    }
    long long int sum=freq[0];
    int lim=(k%2 ? 1+k/2 : k/2);
    for(int i=1; i<lim; i++)
    {   sum+=max(freq[i], freq[k-i]);
    }
    printf("%d",sum);
    return 0;
}
