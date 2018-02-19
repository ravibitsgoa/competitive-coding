#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000005, MAXIND=4*MAXN, MOD = 1e9+7;
int Mintree[MAXIND], Maxtree[MAXIND], Array[MAXN]={0};
long long summin[MAXIND]={0}, summax[MAXIND]={0};

void init(void)
{ for(int i=0; i<MAXIND; i++)
  { Mintree[i]=-1;
    Maxtree[i]=-1;
  }
}

void initialize(int node, int b, int e, int N)
{ if (b == e)
  { Mintree[node] = b;
    Maxtree[node] = b;
    summax[node]=summin[node]  = Array[b] % MOD;
  }
  else
  { initialize(2*node,      b,            (b+e)/2,  N);
    initialize(2*node + 1,  (b+e)/2 + 1,  e,        N);
    if (Array[Mintree[2*node]] <= Array[Mintree[2*node + 1]])
      Mintree[node] = Mintree[2*node];
    else
      Mintree[node] = Mintree[2*node + 1];
    if (Array[Maxtree[2*node]] <= Array[Maxtree[2*node + 1]])
      Maxtree[node] = Maxtree[2*node +1];
    else
      Mintree[node] = Mintree[2*node];
    summin[node] = (summin[2*node] + summin[2*node + 1] + Mintree[node]) %MOD;
    summax[node] = (summax[2*node] + summax[2*node + 1] + Maxtree[node]) %MOD;
  }
}

long long minquery(int node, int b, int e, int i, int j, int i0, int j0)
{
  long long p1, p2;
  if (i > e || j < b)
    return -summin[node];

  if (b >= i && e <= j && j0<b)
    return summin[node]%MOD;

  p1 = minquery(2*node,     b,           (b+e)/2,  i, j, i0, j0);
  p2 = minquery(2*node + 1, (b+e)/2 + 1, e,        i, j, i0, j0);

  //if(p1==-1 && p2==-1)
    //return 0;
  //if(p1==-1)
    //return p2%MOD;
  //if(p2==-1)
    //return p1%MOD;
  return (p2 + p1) %MOD;
}

long long maxquery(int node, int b, int e, int i, int j, int i0, int j0)
{
  long long p1, p2;
  if (i > e || j < b)
    return -1;

  if (b >= i && e <= j && i0>e)
    return summax[node]%MOD;

  p1 = maxquery(2*node,     b,           (b+e)/2,  i, j, i0, j0);
  p2 = maxquery(2*node + 1, (b+e)/2 + 1, e,        i, j, i0, j0);

  if(p1==-1 && p2==-1)
    return 0;
  if(p1==-1)
    return p2%MOD;
  if(p2==-1)
    return p1%MOD;
  return (p2 + p1) %MOD;
}

int main(void)
{ init();
  int N;
  cin>>N;
  for(int i=0; i<N; i++)
  { cin>>Array[i];
  }
  initialize(1, 0, N-1, N);
  cout<<minquery(1, 0, N-1, 1, N, 0, 0)<<'\n';
  long long ans=(minquery(1, 0, N-1, 1, N, 0, 0)*maxquery(1, 0, N-1, 0, 0, 1, N))%MOD;
  for(int i=1; i<N-1; i++)
  { cout<<ans<<'\n';
    ans = (ans + (minquery(1, 0, N-1, i+1, N-1, 0,i)-minquery(1, 0, N-1, i, N-1, 0,i-1))*(maxquery(1, 0, N-1, 0, i, i+1, N-1)-maxquery(1, 0, N-1, 0, i-1, i, N-1)))%MOD;
  }
  cout<<ans;
  return 0;
}
