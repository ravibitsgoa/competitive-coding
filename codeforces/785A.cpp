#include<iostream>
using namespace std;
int main()
{ int n, ans=0;
  cin>>n;
  string x;
  while(n--)
  { cin>>x;
    if(x=="Tetrahedron")
      ans+=4;
    else if(x=="Cube")
      ans+=6;
    else if(x=="Octahedron")
      ans+=8;
    else if(x=="Dodecahedron")
      ans+=12;
    else
      ans+=20;
  }
  cout<<ans;
  return 0;
}
