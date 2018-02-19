//New year transportation
#include<iostream>
using namespace std;
int main()
{   int n, t, i=1, x, flag=0;
    cin>>n>>t;
    for(int j=1; j<n; j++)
    {   cin>>x;
        if(j==i)
        {   i+=x;
        }
        if(i==t && flag==0){cout<<"YES"; flag=1;}
    }
    if(flag==0)
    {   cout<<"NO";
    }
    return 0;
}
