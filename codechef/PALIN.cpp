#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int k;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>k;
  string x;
  while(k--)
  { cin>>x;
    /*int l=x.length(), flag=0;
    for(int i=(l-1); i>(l-1)/2; i--)
    { if(x[l-1-i]<x[i])
      { int j=i;
        while(x[j]=='9')
        { x[j]='0';
          j--;
        }
        if(j>-1)
          x[j]++;
        else
        { x.insert(0, "1");
          l++;
        }
        i=l;
        flag=1;
      }
      else if(x[l-1-i]==x[i])
      { int k=i-1;
        while(x[k]==x[l-1-k])
          k--;
        if(k>-1 || flag==0)
        { if(x[i-1]<'9')
            x[i-1]++;
          else
          { int j=i;
            while(x[j]=='9')
            { x[j]='0';
              j--;
            }
            if(j>-1)
              x[j]++;
            else
            { x.insert(0, "1");
              l++;
            }
            i=l;
          }
          flag=1;
        }
        else
          break;
      }
      if(x[i]<x[l-1-i])
      { flag=1;
        x[i]=x[l-1-i];
      }

      //cout<<x<<endl;
      //cout<<i<<' '<<x<<endl;
    }
    //if(c!="a")
      //cout<<c;
    if(l>1)
      cout<<x<<endl;
    else
      cout<<"11"<<endl;*/
    next_permutation(x.begin(),x.end());
    cout<<x<<'\n';
  }
  return 0;
}
