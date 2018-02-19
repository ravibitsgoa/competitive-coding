#include<iostream>
using namespace std;
int main()
{ int sum=0, n, x, m=0;
  cin>>n;
  int inp[n];
  for(int i=0; i<n; i++)
  { cin>>inp[i];
    m=max(m,inp[i]);
  }
  for(int i=0; i<n; i++)
    sum+=m-inp[i];
  cout<<sum;
  return 0;
}
