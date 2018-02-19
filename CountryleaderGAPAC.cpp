#include<algorithm>
#include<iostream>
using namespace std;
int calc(string inp)
{ int ans=0;
  sort(inp.begin(),inp.end());
  for(int i=0; i<inp.length()-1; i++)
  { if('A'<=inp[i]  && inp[i]<='Z' && inp[i]!=inp[i+1])
      ans++;
  }
  if(inp[inp.length()-1]!=inp[inp.length()-2])
    ans++;
  return ans;
}
int main()
{ int t;
  cin>>t;
  for(int j=1; j<=t; j++)
  { int n;
    cin>>n;
    string x[n];
    for(int i=0; i<n; i++)
    { // getline(cin, x[i]);
      cin>>x[i];
      //cout<<i;
    }
    sort(x,x+n);
    int leader=0, num[n];

    for(int i=0; i<n; i++)
    { num[i]=calc(x[i]);
    }
    for(int i=1; i<n; i++)
    { if(num[i]>num[leader])
        leader=i;
      else if(num[i]==num[leader])
      { if(x[i][0]<x[leader][0])
          leader=i;
      }
    }
    cout<<"Case #"<<j<<": "<<x[leader]<<'\n';
    //cout<<'h';
  }
return 0;
}
