#include<algorithm>
#include<iostream>
#include<vector>
const int INF=1<<30;
using namespace std;
bool fun(pair<int, int> x, pair<int, int> y)
{ double one=x.first /(double) x.second, two=y.first /(double) y.second;
  return one>=two;
}
int main()
{ int n, powercharger;
  cin>>n>>powercharger;
  vector<pair<int, int> > inp (n);
  for(int i=0; i<n; i++)
  { int pw, bat;
    cin>>pw>>bat;
    inp[i]={pw, bat};
  }
  sort(inp.begin(), inp.end(), fun);
  double tnext=inp[1].second/(double)inp[1].first;
  double totalt=tnext;
  double tfinish[n+1]={0};
  for(int i=0; i<n; i++)
  { tfinish[i]=(inp[i].second +(min(tnext, totalt)-(inp[i].second/inp[i].first))*powercharger) /(double) (inp[i].first);
    if(inp[i].first<powercharger)
      tfinish[i]=INF;
    if(i==0)
      totalt=tfinish[0];
    else
      totalt=max(tfinish[i], totalt);
    if(i<n-1)
      tnext=inp[i+1].second/(double)inp[i+1].first;
    else
      tnext=INF;
  }
  for(int i=0; i<n; i++)
    cout<<tfinish[i]<<' ';
    //totalt=min(totalt, tfinish[i]);
  if(totalt==INF)
    cout<<-1;
  else
    cout<<totalt;
    //cout<<inp[i].first<<' '<<inp[i].second<<endl;
return 0;
}
