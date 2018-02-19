#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp = boost::multiprecision;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   mp::cpp_int N, K, ans=0;
        cin>>N>>K;
        mp::cpp_int power=1;
        while(N--)
            power*=2;
        N= power;
        N>>=1;
        for(mp::cpp_int i=1; i<=N; i*=2)
        {   if(K & i)
                ans+=N/i;
            //N>>=1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
