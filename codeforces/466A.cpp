#include<iostream>
using namespace std;
int main()
{   int n, m, a, b;
    cin>>n>>m>>a>>b;
    if(a< (float)(b/m))
    {   cout<<n*a;
    }
    else
    {   int ans=b*(int)(n/m);
        if(a*(n%m) < b) ans+= a*(n%m);
        else ans+=b;
        cout<<ans;
    }
    return 0;
}
