#include<iostream>
using namespace std;
int main()
{ int n, m;
  cin>>n>>m;
  int a[m];
  for(int i=0; i<m; i++)
    cin>>a[i];
  int arr[n+1]={0};
  for(int i=1; i<m; i++)
  { int tmp=(arr[a[i-1]] + a[i-1]);
    if(arr[a[i-1]]==0)
    { arr[a[i-1]]=a[i]-a[i-1];
      if(arr[a[i-1]]<=0)
        arr[a[i-1]]+=n;
    }
    else if(tmp != a[i] || (tmp>=n && ((tmp+1)%n) !=a[i]))
    { cout<<-1;
      return 0;
    }
  }
  bool x=1;
  for(int i=1; i<=n; i++)
    x*=arr[i];
  if(!x)
  { cout<<-1;
  }
  else
  {
    for(int i=1; i<=n; i++)
      cout<<arr[i]<<' ';
  }
return 0;
}
