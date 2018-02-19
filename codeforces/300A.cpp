#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];
  sort(arr, arr+n);

  int i;
  for(i=0; arr[i]<0; i++){}
  int neg=i;
  for(; arr[i]==0; i++){}
  int zero=i;
//initialization complete.
  int pos=n-zero;
  cout<<1<<' '<<arr[0]<<endl;
  if(neg>=3)
  { cout<<2<<' '<<arr[1]<<' '<<arr[2]<<endl;
    cout<<n-3<<' ';
    for(int j=3; j<n; j++)
      cout<<arr[j]<<' ';
  }
  else
  { cout<<1<<' '<<arr[zero]<<endl;
    cout<<n-2<<' '<<arr[1]<<' ';
    for(int j=2; j<n; j++)
    { if(j!=zero)
        cout<<arr[j]<<' ';
    }
  }
  return 0;
}
