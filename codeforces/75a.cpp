#include<iostream>
using namespace std;
int main()
{ long long int x, y, sum;
  cin>>x>>y;
  sum=x+y;
  for(long long int i=10; i<=x; i*=10)
  { if(x%i == x%(i/10))
    { long long int t= x%i;
      x/=i;
      x*=(i/10);
      x+=t;
      i=10;
    }
  }
  for(long long int i=10; i<=y; i*=10)
  { if(y%i == y%(i/10))
    { long long int t= y%i;
      y/=i;
      y*=(i/10);
      y+=t;
      i=10;
    }
  }
  for(long long int i=10; i<=sum; i*=10)
  { if(sum%i == sum%(i/10))
    { long long int t= sum%i;
      sum/=i;
      sum*=(i/10);
      sum+=t;
      i=10;;
    }
  }
  cout<<x<<' '<<y<<' '<<sum<<endl;
  if(x+y != sum)
    cout<<"NO";
  else
    cout<<"YES";
  return 0;
}
