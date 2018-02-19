#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b)
{   if(a==0)        return b;
    else if(b==0)   return a;
    else if(a>b)    return gcd(a%b, b);
    else return gcd(a, b%a);
}
int main()
{   int t;
    cin>>t;
    while(t--)
    {   long long int a;
        string b;
        cin>>a>>b;
        long long int ans=0;
        if(a==0)
        {   cout<<b;
            continue;
        }
        for(int i=0; i<b.size(); i++)
            ans=(ans*10 + b[i] - '0') %a;
        ans=gcd(a, ans);
        cout<<ans<<endl;
    }
    return 0;
}
