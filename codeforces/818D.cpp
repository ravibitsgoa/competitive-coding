#include<iostream>
using namespace std;
int main()
{ int n, A;
  cin>>n>>A;
  int c[n];
  int freq[1000005]={0};
  int ans=0, maxfreq=0;
  for(int i=0; ans!=-1 && i<n; i++)
  { cin>>c[i];
    freq[c[i]]++;
    if(freq[c[i]]>maxfreq)
    { maxfreq=freq[c[i]];
      if(c[i]==A)
        ans=-1;
      else if(ans!=-1)
        ans=c[i];
    }
  }
  cout<<ans;
return 0;
}
