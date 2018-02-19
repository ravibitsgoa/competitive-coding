#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ int n, k;
  cin>>n>>k;
  int a[n], b[k];
  for(int i=0; i<n; i++)
    cin>>a[i];
  for(int i=0; i<k; i++)
    cin>>b[i];
  sort(b, b+k);
  reverse(b, b+k);
  int i=0, j=0;
  for(; i<n && j<k; )
  { if(a[i]==0)
      a[i++]=b[j++];
    else
      i++;
  }
  bool ans=0;
  for(i=1; i<n; i++)
  { if(a[i-1]>a[i])
      ans=1;
  }
  if(ans)
    cout<<"Yes";
  else
    cout<<"No";
return 0;
}
