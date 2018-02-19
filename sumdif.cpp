#include<iostream>
#include<map>
using namespace std;
int main()
{ int n, q;
  cin>>n>>q;
  int a;
  map<int,bool>chhe;
  for(int i=0; i<n; i++)
  { cin>>a;
    chhe[a]=1;
  }
  int count=0;
  while(q--)
  { int sum, diff;
    cin>>sum>>diff;
    int x=sum + diff, y=sum-diff;
    if(x%2==0 && y%2==0 && chhe[x/2] && chhe[y/2])
      count++;
  }
  cout<<count;
return 0;
}
