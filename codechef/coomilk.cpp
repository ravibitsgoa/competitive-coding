#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int flag=0;
    string x[n];
    for(int i=0; i<n; i++)
      cin>>x[i];
    for(int i=0; i<n; i++)
      if(x[i]=="cookie" && ((i<n-1 && x[i+1]!="milk") || i==n-1))
      { flag=1;
      }
    if(flag)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
  }
  return 0;
}
