#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
      cin>>a[i];
    int maxsum[n]={0},start[n]={0}, end, absmax=0, sum=0;
    start[0]=0;
    maxsum[0]=a[0];
    if(a[0]>0) sum=a[0];
    for(int i=1; i<n; i++)
    { if(a[i]>0)
        sum+=a[i];
      if(maxsum[i-1]>0)
      { maxsum[i]=(maxsum[i-1]);
        start[i]=start[i-1];
      }
      else
      { start[i]=i;
      }
      maxsum[i]+=a[i];
      if(maxsum[i]>absmax)
      { absmax=maxsum[i];
        end=i;
      }
    }
    //for(int j=start[end]; j<=end; j++)
      //cout<<a[j]<<' ';
    cout<<absmax<<' '<<sum<<endl;
  }
  return 0;
}
