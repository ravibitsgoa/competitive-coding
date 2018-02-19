#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { double ds, dt, d;
    cin>>ds>>dt>>d;
    if(d>(ds+dt))
      cout<<d-ds-dt;
    else
      cout<<(double)0.00;
    cout<<'\n';
  }
return 0;
}
