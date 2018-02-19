#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { int N, Q;
    cin>>N>>Q;
    int i=0, temp, inp[N+1], freq[N]={0}, cumulfreq[N]={0};
    cin>>inp[0];
    freq[0]=cumulfreq[0]=1;
    for(int j=1; j<N+1; j++)
    { cin>>temp;
      if(inp[i]==temp)
        freq[i]++;
      else
      { i++;
        inp[i]=temp;
        freq[i]++;
      }
      cumulfreq[i]=j+1;
      //cin>>inp[j];
    }
    while(Q--)
    { int i, j, k, z;
      cin>>i>>j>>k;
      int ans=0;
      for(z=0; cumulfreq[z]<i; z++)
      {}
      if(cumulfreq[z]<i && cumulfreq[z+1]>i && freq[z]>=k)
        ans++;
      for(; cumulfreq[z]<=j; z++)
      { if(freq[z]>=k)
          ans++;
      }
      if(cumulfreq[z]>j && cumulfreq[z-1]<j && freq[z]>=k)
        ans++;
      int curr=0;
      if(inp[i]==inp[i+1])
        curr++;
      else if(k==1)
        ans++;
      for(i++; i<j+1; i++)
      { if(inp[i]==inp[i-1])
          curr++;
        else
        { if(curr>=k)
            ans++;
          curr=1;
          //cout<<i<<'h'<<ans<<endl;
        }
      }
      if(curr>=k)
        ans++;
      cout<<ans<<'\n';
    }
  }
return 0;
}
