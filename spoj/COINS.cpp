//http://www.spoj.com/problems/COINS/
#include<iostream>
#include<map>
using namespace std;
map<long long, long long> ans;
long long f(long long n)
{   if(n<12)
        return n;
    if(ans[n]>=n)
        return ans[n];
    else
        return ans[n]= max(n, f(n/2)+ f(n/3)+ f(n/4));
}
int main()
{   long long n=0, nlast=-1;
    cin>>n;
    while(n!=nlast)
    {   cout<<f(n)<<'\n';
        nlast= n;
        cin>>n;
    }
    return 0;
}
