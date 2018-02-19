#include<bits/stdc++.h>
#define ll long long
int gcd(int x, int y)
{	if(x==0) return y;
	else if(y==0) return x;
	else if(x<y) return gcd(x, y%x);
	else if(y<x) return gcd(x%y, y);
	else return y;
}

using namespace std;
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--)
  { int a, b, gc=__gcd(a,b);
    cin>>a>>b;
    /*for(int i=0; i<numprime; i++)
    { int temp=0;
      while(gc%primes[i]==0)
      { temp++;
        gc/=primes[i];
      }
      if(temp>1)

    }*/
    cout<<gc;
    if(gc!=1)
      cout<<"Yes"<<'\n';
    else
      cout<<"No"<<'\n';
  }
return 0;
}
