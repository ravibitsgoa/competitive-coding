#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{ int n, q;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>q;
  int A[n], S[n], x, j=0, sumofS[n];
  for(int i=0; i<n; i++)
  { cin>>x;
    if(i==0)
    { A[j]=x;
      S[j]=1;
      j++;
    }
    else if(x!=A[j-1])
    { A[j]=x;
      S[j]=1;
      sumofS[j-1]=(sumofS[j-2]*(j>1))+S[j-1];
      j++;
    }
    else if(x==A[j-1])
    { S[j-1]++;
    }
  }
  while(q--)
  { int l, r, k, ans=-1, count=0;
    cin>>l>>r>>k;
    //int *start=lower_bound(sumofS, sumofS+j, l);
    int p;
    //cout<<p<<endl;
    for(p=0; p<j && count<l; p++){count+=S[p];}
    cout<<p;
    for(; count<=r && p<j; count+=S[p], p++)
    { cout<<S[p];
      if(S[p]>=k)
      { ans=A[p];
        break;
      }
    }
    cout<<ans<<'\n';
  }
return 0;
}
