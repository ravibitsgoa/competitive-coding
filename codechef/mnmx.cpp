#include<iostream>
using namespace std;
int main()//beginner on codechef.com
{ int t;
  cin>>t;
  while(t--)
  { int n, min, i, x;
    cin>>n>>min;
    for(i=1; i<n; i++)
    { cin>>x;
      if(x<min) min=x;
    }
    cout<<(long long)(n-1)*min<<endl;
  }
  return 0;
}
