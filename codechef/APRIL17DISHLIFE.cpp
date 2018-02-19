using namespace std;
#include <bits/stdc++.h>
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  { int N, K;
    cin>>N>>K;
    int got[K]={0}, gotingred=0;
    bool x=0; //jaldi patyu ke nahi eno bullion.
    while(N--)
    { if(gotingred==K)
        x=1;
      int numofingred;
      cin>>numofingred;
      int i;
      while(numofingred--)
      { cin>>i;
        if(got[i-1]==0)
        { got[i-1]=1;
          gotingred++;
        }
      }
    }
    if(x==1 && gotingred==K)
      cout<<"some"<<'\n';
    else if(x==0 && gotingred==K)
      cout<<"all"<<'\n';
    else if(gotingred<K)
      cout<<"sad"<<'\n';
  }
return 0;
}
