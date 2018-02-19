#include<iostream>
using namespace std;
int main()
{ string x, y, m;
  cin>>x>>y;
  int n;
  cin>>n;
  cout<<x<<' '<<y<<endl;

  while(n--)
  { cin>>m;
    if(x==m)
      cin>>x;
    else
      cin>>y;
    cout<<x<<' '<<y<<endl;
  }
  return 0;
}
