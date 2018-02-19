#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{   int i, f[100001];
    f[0]=0; f[1]=1;
    for(i=2; i<=100000; i++)
        f[i]=(f[i-1]+f[i-2])%(1000000007);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=100000, n;
    cin>>t;
    while(t--)
    {   cin>>n;
        cout<<f[n]<<'\n';
    }
    return 0;
}
