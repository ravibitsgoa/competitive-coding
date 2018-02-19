//codechef beginner problem : movie weekend
#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int n;
    cin>>n;
    int l[n], r[n];
    for(int i=0; i<n; i++)  cin>>l[i];
    for(int i=0; i<n; i++)  cin>>r[i];
    for(int i=0; i<n; i++)  l[i]*=r[i];

    int ans=0;
    for(int i=1; i<n; i++)
    { if(l[i] > l[ans])
        ans=i;
      else if(l[i]==l[ans] && r[i]>r[ans])
        ans=i;
    }
    cout<<ans+1<<'\n';
  }

}
