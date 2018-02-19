#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  for(int i=1; i<=t; i++)
  { string N, out;
    cin>>N;
    out=N;
    bool x=0; //not done.
    sort(out.begin(), out.end());
    for(int j=out.length()-1; j>=0 && x==0; j--)
    { for(char k=out[j]; k<='9'; k++)
      { char temp=out[j];
        out[j]=k;
        if(out>N)
        { out[j]=temp;
          x=1;
          break;
        }
      }
    }
    while(out[0]<'9')
    { string t=out;
      out[0]++;
      for(int j=1; j<out.length(); j++)
        out[j]=out[j-1];
      bool x=0;
      if(out<N)
      { for(int j=out.length()-1; j>=0 && x==0; j--)
        { for(char k=out[j]; k<='9'; k++)
          { char temp=out[j];
            out[j]=k;
            if(out>N)
            { out[j]=temp;
              x=1;
              break;
            }
          }
        }
      }
      else
      { out=t;
        break;
      }
    }
    //cout<<out;
    cout<<"Case #"<<i<<": ";
    int j;
    for(j=0; j<out.length(); j++)
    { if(out[j]!='0')
        break;
    }
    for(; j<out.length(); j++)
      cout<<out[j];
    cout<<'\n';
  }
return 0;
}
