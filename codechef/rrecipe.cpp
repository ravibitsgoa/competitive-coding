#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   string x;
        cin>>x;
        int n=x.length();
        int ans=1;
        if(n%2 && x[n/2]=='?') ans*=26;
        for(int i=0; i<n/2; i++)
        {   if(x[i]=='?' && x[n-i-1]=='?')
                ans*=26;
            else if(x[i]=='?' || x[n-i-1]=='?')
                ans*=1;
            else if(x[i]!=x[n-i-1])
                ans=0;
            ans%=10000009;
        }
        cout<<ans<<endl;
    }
    return 0;
}
