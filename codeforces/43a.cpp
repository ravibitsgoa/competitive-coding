#include<iostream>
using namespace std;
int main()
{ int n, nx=0, ny=0;
  cin>>n;
  string x, y;
  cin>>x; nx=1;
  n--;
  while(n--)
  { string a;
    cin>>a;
    if(a==x) nx++;
    else
    { if(y=="") y=a;
      ny++;
    }
  }
  if(ny<nx) cout<<x;
  else cout<<y;
return 0;
}
