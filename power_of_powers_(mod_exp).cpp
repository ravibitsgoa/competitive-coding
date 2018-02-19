#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1, x, y, m;
    long long int ans=0;
    //cin>>t;
    while(t--)
    {   //cin>>x>>y>>m;
        y=3;
        x=10;
        //m=17;
        ans=x%m;
        while(y>1)
        {   if(y%2)
                ans=(ans*ans*x)%m;
            else
                ans=(ans*ans)%m;
            y/=2;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
