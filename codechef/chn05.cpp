#include<iostream>
#include<vector>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n, m;
        cin>>n>>m;
        if(n==1)
            cout<<0<<'\n';
        else if(n==2)
            cout<<m<<'\n';
        else
            cout<<2*m + n-3<<'\n';
    }
    return 0;
}
