#include<cmath>
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int x, y;
    cin>>x>>y;
    for(int z=1; z<=1000; z++)
    { bool is_sum_prime=true;
      for(int i=2; i<=sqrt(x+y+z)+1; i++)
      { if((x+y+z) % i ==0)
        { is_sum_prime=false;
          break;
        }
      }
      if(is_sum_prime==true)
      { cout<<z<<'\n';
        break;
      }
    }

  }
return 0;
}
