#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{   int t, k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin>>t;
    t=1000;
    while(t--)
    {   //cin>>k;
        k=1000000000;
        while(k>=10)
        {   int sum=0;
            while(k)
            {   sum+=k%10; k/=10;
            }
            k=sum;
        }
        if(k==1)
            cout<<"Happy Number";
        else
            cout<<"Unhappy";
        cout<<'\n';
    }
    return 0;
}
