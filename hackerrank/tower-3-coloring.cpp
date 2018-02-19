#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long mypow(long long x, long long n)
{ if(n==0)
    return 1;
  else if(n==1)
    return x%MOD;
  long long temp=mypow(x, n/2)%MOD;
  if(n%2 == 0)
    return (temp*temp) % MOD;
  else
    return (temp*((temp*x) %MOD)) %MOD;
}
long long towerColoring(long long n){
    return mypow(3,mypow(3,n) % MOD) %MOD;
}

int main() {
    int q;
    cin>>q;
    while(q--)
    { long long n;
      cin >> n;
      long long result = towerColoring(n);
      cout << result << endl;
    }
    return 0;
}

