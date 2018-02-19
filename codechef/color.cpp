//codechef beginner problem :chef and coloring
#include <iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n, r=0, g=0, b=0;
    cin>>n;
    string x;
    cin>>x;
    for(int i=0; i<n; i++)
    { switch (x[i])
      { case 'R': r++; break;
        case 'G': g++; break;
        case 'B': b++; break;
      }
    }
    cout<<min(r+g, min(r+b, g+b))<<'\n';
  }
  
return 0;
}
