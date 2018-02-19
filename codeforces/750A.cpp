#include<iostream>
using namespace std;
int main()
{   int n, k;
    cin>>n>>k;
    int ans=1;
    k=240-k;
    while(k>=(5*ans))
    {   k-=5*ans;
        ans++;
        //cout<<k<<' '<<ans<<endl;
    }
    if(ans>n)
        cout<<n;
    else
        cout<<ans-1;
    return 0;
}
