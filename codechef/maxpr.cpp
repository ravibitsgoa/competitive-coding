#include <iostream>
#include <cassert>
const int MOD = 1e9 + 7;
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
        cin>>n;
        int A[n], mx=0, mn=100;
        for(int i=0; i<n; i++)
        {   cin>>A[i];
            mx=max(mx, A[i]);
            mn=min(mn, A[i]);
        }
        long long ans=0;
        for(int diff=-100; diff<=100; diff++)
        {   cout<<ans<<' ';
            long long cur=0, dp[n]={0};
            long long sum[100]={0};
            for(int i=0; i<n; i++)
            {   //dp=0;
                if((A[i]-diff) >=mn and (A[i]-diff)<=mx)
                {   cout<<A[i]<<' '<<diff<<'\n';
                    dp[i] = sum[A[i]-diff]+1;
                }
                sum[A[i]] = (sum[A[i]] + dp[i])%MOD;
                cur = (cur + dp[i])%MOD;
            }
            ans = (ans + cur)%MOD;
            if(cur>0)
                ans -= n;
        }
        ans+=n;
        long long mul=1;
        for(int i=0; i<n; i++)
            mul = (mul*2)%MOD;
        ans = (mul - 1 -ans) %MOD;
        assert(ans>=0);
        cout<<ans<<'\n';
    }
    return 0;
}
