#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { long long int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++)  cin>>x;
    cout<<(long long)(n*(n-1)/2)<<endl;
  }
return 0;
}
