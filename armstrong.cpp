#include<iostream>
#include<cstdio>
#include <bits/stdc++.h>
using namespace std;
int isarm(int a)
{   int acopy=a, x;
    while(acopy)
    {   x=acopy%10;
        a-=(x*x*x);
        acopy/=10;
    }
    if(!a)  return 1;
    else    return 0;
}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q=100000, l,r, ans=0, arr[10], j=0;
    for(int i=1; i<100001; i++)
    {   if(isarm(i))
        {   arr[j]=i;
            j++;
        }
    }//Stretching it to limits.
    //printf("%d",j);
    //scanf("%d,&Q);
    while(Q--)
    {   //scanf("%d%d",&l,&r);
        l=1; r=100000;
        for(int i=0; i<j; i++)
        {   if(arr[i]>=l && arr[i]<=r)
                ans++;
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}
