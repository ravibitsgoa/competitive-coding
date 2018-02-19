#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ int n=1;
  while(n)
  { cin>>n;
    if(n==0) break;
    int a[n], ans=0;
    for(int i=0; i<n; i++)
      cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++)
    { for(int j=i+1; j<n; j++)
      { for(int k=j+1; k<n; k++)
        { if(a[i]+a[j]<a[k])
          { ans+=n-k; break;
          }
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
