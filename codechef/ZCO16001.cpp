#include<set>
#include<iostream>
#include<cassert>
using namespace std;
int main()
{ long long n;
  cin>>n;
  long long k;
  cin>>k;
  long long a[n], b[n];
  for(long long i=0; i<n; i++)  cin>>a[i];
  for(long long i=0; i<n; i++)  cin>>b[i];
  multiset<long long> f(a, a+n), s(b, b+n);
  long long skew = *(f.rbegin()) + *(s.rbegin());
  while(k--)
  { if(*(f.rbegin()) > *(s.begin()) && *(f.rbegin()) < *(s.rbegin()))
    { long long p = *(f.rbegin()), q=*(s.begin());
      auto it=f.end();
      it--;
      f.erase(it);
      s.erase(s.begin());
      f.insert(q);
      s.insert(p);
    }
    else if(*(s.rbegin()) > *(f.begin()) && *(s.rbegin()) < *(f.rbegin()))
    { long long p = *(s.rbegin()), q=*(f.begin());
      auto it=s.end();
      it--;
      s.erase(it);
      f.erase(f.begin());
      s.insert(q);
      f.insert(p);
    }
    //cout<<f.size()<<' '<<s.size()<<endl;
    assert(f.size()==s.size());
    if(skew >= *(f.rbegin()) + *(s.rbegin()))
      skew = *(f.rbegin()) + *(s.rbegin());
    else
      assert(0);
  }
  cout<<skew;
  return 0;
}
