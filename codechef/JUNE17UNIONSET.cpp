#include<cstring>
#include<iostream>
using namespace std;
bool inp[2505][2505]={0};
int main()
{ int T;
  cin>>T;
  while(T--)
  { memset(inp, 0, 2505*2505);
    int N, K;
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    { int l;
      cin>>l;
      while(l--)
      { int x;
        cin>>x;
        inp[i][x]=1;
      }
    }
    long long ans=0;
    for(int i=1; i<=N; i++)
    { for(int j=i+1; j<=N; j++)
      { int k;
        for(k=1; k<=K && (inp[i][k] || inp[j][k]); k++)
        { }
        if(k==K+1)
          ans++;
      }
    }
    cout<<ans<<'\n';
  }
return 0;
}
