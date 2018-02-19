#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ int n, x, y;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>x>>y;
  unordered_map<int,int> A[n], B[n];
  for(int i=0; i<n; i++)
    cin>>A[i];
  for(int i=0; i<n; i++)
    cin>>B[i];
  /*int Amax=0, Bmax=0, Ai, Bj, ans=0;
  for(int i=0; i<n; i++)
  { Amax=0; Bmax=0;
    for(int j=0; j<n; j++)
    { if(A[j]>Amax){Amax=A[j]; Ai=j;}
      if(B[j]>Bmax){Bmax=B[j]; Bj=j;}
    }
    if(Amax>=Bmax)
    { ans+=Amax;
      //cout<<Ai<<'A';
      A[Ai]=0; B[Ai]=0;
    }
    else
    { ans+=Bmax;
      //cout<<Bj<<'B';
      B[Bj]=0; A[Bj]=0;
    }
    //cout<<ans<<endl;
  }*/
  sort(A, A+n, );
  cout<<ans;
  return 0;
}
