#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int a[n][n];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin>>a[i][j];
  bool ans=1;
  for(int i=0; i<n; i++)
  { for(int j=0; j<n; j++)
    { if(a[i][j]!=1)
      { bool part=0;
        for(int x=0; !part && x<n; x++)
          for(int y=0; !part && y<n; y++)
            if(x!=j && y!=i && a[i][x]+a[y][j] == a[i][j])
              part=1;
        ans*=part;
      }
    }
  }
  if(ans)
    cout<<"Yes";
  else
    cout<<"No";
return 0;
}
