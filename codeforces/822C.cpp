#include<cstdio>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int main()
{ int n, x;
  scanf("%d %d",&n,&x);
  pair<pair<long long, long long>, long long> choices[n];
  long long l, r, cost;
  for(int i=0; i<n; i++)
  { scanf("%lld %lld %lld",&l,&r,&cost);
    choices[i].second=cost;
    choices[i].first.first=l;
    choices[i].first.second=r;
  }
  long long min_cost=1e10, bestCost[x+1];
  sort(choices, choices+n);
  for(int i=0; i<=x; i++)
    bestCost[i]=1e10;
  int j=0;
  for(int i=0; i<n; i++)
  { l=choices[i].first.first;
    r=choices[i].first.second;
    cost=choices[i].second;
    if(choices[0].first.second>=l)
      continue;
    if(r-l+1 <x)
    { for(; choices[j].first.second<l && j<i; j++)
      { long long len=choices[j].first.second - choices[j].first.first +1;
        if(len<=x)
          bestCost[len]=min(bestCost[len], choices[j].second);
      }
      min_cost=min(min_cost, bestCost[x-(r-l+1)]+ cost);
    }
  }
  if(min_cost==1e10)
    cout<<-1;
  else
    cout<<min_cost;
return 0;
}
