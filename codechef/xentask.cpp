#include<bits/stdc++.h>
using namespace std;
int main()
{ int t;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int x[n], y[n], sum1=0, sum2=0;
    for(int i=0; i<n; i++)
      cin>>x[i];
    for(int i=0; i<n; i++)
      cin>>y[i];

    for(int i=0; i<n; i++)
    { if(i%2)
      { sum1+=x[i];
        sum2+=y[i];
      }
      else
      { sum1+=y[i];
        sum2+=x[i];
      }
    }
    cout<<min(sum1,sum2)<<'\n';
  }
return 0;
}
