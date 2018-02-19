#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    int d[n], sum=0;
    for(int i=0; i<n; i++)
    {   cin>>d[i];
        sum+=d[i];
    }
    int s,t;
    cin>>s>>t;
    if(s>t){int temp=s; s=t; t=temp;}
    int dcw=0;
    s--; t--;
    for(int i=s; i<t; i++)
        dcw+=d[i];
    int ans=min(dcw, sum-dcw);
    cout<<ans;
    return 0;
}
