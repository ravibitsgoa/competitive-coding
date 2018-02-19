//link: http://opc.iarcs.org.in/index.php/problems/PYRAMID
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
  { int x, y;
    cin>>x>>y;
    a[i]=min(x, y);
  }
  sort(a, a+n);
  for(int i=0; i<n; i++)
    a[i]=min(a[i-1]+1, a[i]);
  cout<<a[n-1];
  return 0;
}
