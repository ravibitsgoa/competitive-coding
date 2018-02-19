#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define INF (1<<30)
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
int main()
{ int n;
  string s;
  cin>>n>>s;
  int num=0;
  char x;
  for(int i=0; i<n; i++)
  { if(s[i]=='0')
    { cout<<num;
      num=0;
    }
    else
      num++;
  }
  cout<<num;
	return 0;
}
