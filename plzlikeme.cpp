#include<iostream>
#include<cmath>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { double l, d, s, c;
    cin>>l>>d>>s>>c;
    if(s*pow(1+c, d-1)>=l) cout<<"ALIVE AND KICKING";
    else cout<<"DEAD AND ROTTING";
    cout<<endl;
  }
  return 0;
}
