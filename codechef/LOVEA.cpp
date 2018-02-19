#include<cmath>
#include<iostream>
using namespace std;
unsigned long long sqroot(unsigned long long x, unsigned long long i, unsigned long long f)
{ unsigned long long mid=(i+f)/2, sq=mid*mid;
  //cout<<i<<' '<<f<<'\n';
  if(f==i)
    return i;
	//cout<<mid<<' '<<sq<<' ';
  if(sq<=x && (sq+ 2*mid +1)>x)
    return mid;
  else if(sq>x)
    return sqroot(x, i, mid);
  else
    return sqroot(x, mid, f);
}
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int Q=100000;
  //cin>>Q;
  while(Q--)
  { unsigned long long int a=1, b=100000000000000000, ans=0, l;
    
//cin>>a>>b;//We have to find number of perfect squares between a and b.
    if(b<=1000000000)
      l=b;
    else
      l=1000000001;
    unsigned long long chhota = sqroot(a, 1, l), bada=sqroot(b, 1, l);
    if(chhota*chhota==a)
      ans++;
    ans+=bada-chhota;
    cout<<ans<<'\n';
    //cout<<chhota<<' '<<bada<<endl;
  }

return 0;
}
