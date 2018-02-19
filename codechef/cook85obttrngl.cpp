#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int k, a, b;
        cin>>k>>a>>b;
        a= abs(a-b);
        a= min(a, k-a);
        if(2*a == k)
            cout<<0<<'\n';
        else
            cout<<min(k-a+1, a-1)<<'\n';
    }
    return 0;
}
