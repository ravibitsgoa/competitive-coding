#include <bits/stdc++.h>
using namespace std;
int main()
{ ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  { string row;
    cin>>row;
    long long int i;
    for(i=0; i<row.length(); i++)
    { if(row[i]=='1')
        break;
    }
    long long int zeros=0, ones=0, timemax=0;
    while(i!=row.length())
    { for(; i<row.length() && row[i]=='1'; i++)
      { ones++;
      }
      if(i==row.length())
        break;
      zeros=0;
      for(; i<row.length() && row[i]=='0'; i++)
      { zeros++;
      }
      if(zeros!=0)
        timemax+=ones*(zeros+1);
    }
    cout<<timemax<<'\n';
  }
return 0;
}
