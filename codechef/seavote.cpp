#include<iostream>
using namespace std;
int abs(int x)
{ if(x<0) return -x;
  return x;
}
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int B, sum=0, nz=0;
    for(int i=0; i<n; i++)
    { cin>>B;
      sum+=B;
      if(B>0)
        nz++;
    }
    if(sum>=100 && abs(sum-100)<nz)
      cout<<"YES";
    else
      cout<<"NO";
    cout<<endl;
  }
return 0;
}
