#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  for(int i=1; i<=t; i++)
  { string x, y;
    cin>>x>>y;
    int j=0, k=0;
    for(; j<x.length()&& k<y.length(); )
    { cout<<j<<k<<endl;
      if(x[j]==y[k])
      { j++;
        k++;
      }
      else if(x[j]=='*')
      { j++;
        int diff=0;
        while(diff<4 && k<y.length())
        { k++;
          diff++;
          if(y[k]==x[j] && j<x.length()-1 && k<y.length()-1 && y[k+1]!=x[j+1] && y[k+1]!='*' && x[j+1]!='*')
          { j++;
          }
          else if(y[k]==x[j] && j==x.length()-1)
          {}
          else if(y[k]==x[j] || y[k]=='*')
            break;
          /*else if(k<y.length()-1 && y[k+1]=='*')
          { k++;
            break;
          }*/
        }
      }
      else if(y[k]=='*')
      { k++;
        int diff=0;
        while(diff<4 && j<x.length())
        { j++;
          diff++;
          if(y[k]==x[j] && j<x.length()-1 && k<y.length()-1 && y[k+1]!=x[j+1] && y[k+1]!='*' && x[j+1]!='*')
          { k++;
          }
          else if(y[k]==x[j] && k==y.length()-1)
          {}
          else if(y[k]==x[j] || x[j]=='*')
            break;

        }
        //cout<<j<<k<<endl;
      }
      else
        break;
    }
    cout<<"Case #"<<i<<": ";
    if(j==x.length() && k==y.length())
      cout<<"TRUE";
    else if(j==x.length() && y[k]=='*')
      cout<<"TRUE";
    else if(k==y.length() && x[j]=='*')
      cout<<"TRUE";
    else
      cout<<"FALSE";
    cout<<endl;
  }
  return 0;
}
