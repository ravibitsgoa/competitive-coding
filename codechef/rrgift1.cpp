#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   int n, k, x, even=0;
        cin>>n>>k;
        while(n--)
        {   cin>>x;
            if(x%2==0) even++;
        }
        if(even>=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
