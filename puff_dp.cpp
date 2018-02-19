#include<tuple>
#include<iostream>
#include<algorithm>
using namespace std;
bool custComp(tuple<int,int,int> i, tuple<int,int,int> j)
{ return get<1>(i) <= get<1>(j);
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    tuple<int, int, int> activ[n];
    for(int i=0; i<n; i++)
    { int s, f, w;
      cin>>s>>f>>w;
      activ[i]=std::make_tuple(s,f,w);
    }
    sort(activ, activ+n, custComp);
    int opt[n]={0};
    auto t=lower_bound(activ, activ+n, activ[0].);
    opt[0]=
    for(int i=1; i<n; i++)
    { t=lower_bound(activ, activ+n, activ[i]);
    }
    cout<<opt[n-1];
  }
  return 0;
}
