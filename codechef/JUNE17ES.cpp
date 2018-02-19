//A solution to Euler sum published in June long challenge 2017.
#include<iostream>
const long double e=2.7182818284, beta = e/(e-1);
using namespace std;
long long S(long long n)
{ if(n==0)
    return 0;
  /*if(n==1)
    return 4;
  if(n==2)
    return 8;*/
  long long m=n*(beta-1);
  long long a=m*n + n*(n+1)/2;
  a-=m*(m+1)/2;
  a-=S(m);
  return a;
}/*
long long sume(long long n)
{ long long m=e*n, ans=m*(m+1)/2;
  ans-=S(n*(e-1));
  return ans;
}*/
int main()
{ /*int n;
  cin>>n;
  cout<<sume(n);*/
  long long ans=0;
  for(int i=1; i<=10; i++)
  { ans+=i*beta;
    cout<<i<<' '<<ans<<' '<<S(i)<<endl;
  }
  //cout<<S(2);
  return 0;
}
