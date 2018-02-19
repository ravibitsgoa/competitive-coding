#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    { int n, k, c=0;
      cin>>n>>k;
      for(int i=1; i<n+1 && i<k+1; i++)
      {   if(k%i == 0 && (k/i)<=n) {c++;}
      }
      cout<<c<<endl;
    }
  return 0;
}
