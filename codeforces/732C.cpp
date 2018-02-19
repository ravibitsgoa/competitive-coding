#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ long long int x[3];
  cin>>x[0]>>x[1]>>x[2];
  sort(x,x+3);
  cout<<(x[2]-1-x[0])*(x[0]<x[2])+(x[2]-1-x[1])*(x[1]<x[2]);
  return 0;
}
