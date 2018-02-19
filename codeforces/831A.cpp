#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int i;
  for(i=1; i<n && a[i]>a[i-1]; i++);
  for(; i<n && a[i]==a[i-1]; i++);
  for(; i<n && a[i]<a[i-1]; i++);
  if(i==n)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
