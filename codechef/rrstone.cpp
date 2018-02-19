#include<iostream>
using namespace std;
int main()
{   long long int n, k;
    cin>>n>>k;
    long long int inp[n], mx, mn;
    cin>>inp[0];
    mx=mn=inp[0];
    for(long long int i=1; i<n; i++)
    {   cin>>inp[i];
        if(inp[i]>mx){mx=inp[i];}
        if(inp[i]<mn){mn=inp[i];}
    }
    if(k==0)
    {   for(long long int i=0; i<n-1; i++)
            cout<<inp[i]<<' ';
        cout<<inp[n-1]<<endl;
    }
    else if(k%2==1)
    {   for(long long int i=0; i<n-1; i++)
            cout<<mx-inp[i]<<' ';
        cout<<mx-inp[n-1]<<endl;
    }
    else
    {   for(long long int i=0; i<n-1; i++)
            cout<<inp[i]-mn<<' ';
        cout<<inp[n-1]-mn<<endl;
    }
return 0;
}
