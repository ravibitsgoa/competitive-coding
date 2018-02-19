#include<map>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    long long c[n], w[n];
    for(int i=0; i<n; i++)
      cin>>c[i];
    for(int i=0; i<n; i++)
      cin>>w[i];
    long long ans=0, maxsum=0;
    bool explored[n]={0};
    int begin=0;
    for(int i=0; i<n; i++)
    { if(explored[c[i]])
      { maxsum=max(ans, maxsum);
        for(int j=begin; j<i; j++)
        { explored[c[j]]=0;
          ans-=w[j];
          if(c[j]==c[i])
          {begin=j+1; break;}
        }
      }
      explored[c[i]]=1;
      ans+=w[i];
      maxsum=max(ans, maxsum);
    }
    maxsum=max(ans, maxsum);
    cout<<maxsum<<'\n';
  }
return 0;
}
