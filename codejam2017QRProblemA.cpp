#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  for(int i=1; i<=t; i++)
  { string s;
    cin>>s;
    long long int N=0;//This is the answer.
    int K;
    cin>>K;
    bool x=0;//This shows current position is winable.
    for(int j=0; j<s.length(); j++)
    { if(s[j]=='-')
      { N++;
        s[j]='+';
        if(j+K-1<s.length())
        { for(int z=1; z<K; z++)
          { if(s[j+z]=='-')
              s[j+z]='+';
            else
              s[j+z]='-';
          }
        }
        else
        { x=1;
          break;
        }
      }
    }
    if(x==0)
      cout<<"Case #"<<i<<": "<<N<<'\n';
    else
      cout<<"Case #"<<i<<": IMPOSSIBLE"<<'\n';
  }
return 0;
}
