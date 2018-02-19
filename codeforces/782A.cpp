#include<iostream>
using namespace std;
int main()
{ int n, k;
  cin>>n>>k;
  int kcopy=k;
  int i=1, sign=1;
  while(k)
  { cout<<i<<' ';
    i+=sign*k;
    sign*=-1;
    k--;
  }
  if(i>n)
    return 0;
  cout<<i<<' ';
  i=kcopy+2;
  while(i<=n)
  { cout<<i<<' ';
    i++;
  }
  return 0;
}
