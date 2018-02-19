#include<map>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, x, y;
    cin>>n;
    map<int,int> kingdom;
    for(int i=0; i<n; i++)
    { cin>>x>>y;
      kingdom[x]=y;
    }
    int bombs=0;
    map<int, int>::iterator i, j;
    for(i=kingdom.begin(); i!=kingdom.end();)
    { j=i; j++;
      for(; j!=kingdom.end() && j->first<i->second;j++)
      {
      }
      bombs++;
      i=j;
    }
    cout<<bombs<<'\n';
  }
return 0;
}
